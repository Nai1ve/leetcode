/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 *
 * https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/
 *
 * algorithms
 * Medium (39.60%)
 * Likes:    377
 * Dislikes: 0
 * Total Accepted:    55K
 * Total Submissions: 138.7K
 * Testcase Example:  '[1,1,4,2,3]\n5'
 *
 * 给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要
 * 修改 数组以供接下来的操作使用。
 * 
 * 如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,4,2,3], x = 5
 * 输出：2
 * 解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,6,7,8,9], x = 4
 * 输出：-1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [3,2,20,1,1,3], x = 10
 * 输出：5
 * 解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
#include <vector>

using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // 自己思考未做出，转换方向,正难则反
        int left = 0;
        int n = nums.size();
        int sum = 0;
        for (auto& x : nums) {
            sum += x;
        }
        int sub = sum - x;
        

        if(sub == 0){
            return n;
        }

        int maxLength = 0;
        int right = 0;

        for (; right < n; right++) {
            sub -= nums[right];

            while (sub < 0 && left < right) {
                sub += nums[left];
                left++;
            }

            if (sub == 0) {
                maxLength = max(maxLength, right - left + 1);
                sub += nums[left]; 
                left++;
            }
        }
        if (sub == 0) {
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength==0? -1: n - maxLength;
    }
};
// @lc code=end

