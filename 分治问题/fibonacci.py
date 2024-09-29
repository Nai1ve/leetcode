import numpy as np


class Solution(object):
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        matrix = np.array([[1, 1], [1, 0]])
        result = np.eye(2)

        while n:
            if n & 1:
                result = np.dot(result, matrix)
            matrix = np.dot(matrix, matrix)
            n = n >> 1

        return result[1 , 0]


solution = Solution()
print(f"当n=100时，斐波那契数列的值为:{solution.fib(100)}")