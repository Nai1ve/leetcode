/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode.cn/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (44.78%)
 * Likes:    1658
 * Dislikes: 0
 * Total Accepted:    586.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
 * 
 * 返回这三个数的和。
 * 
 * 假定每组输入只存在恰好一个解。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,0,0], target = 1
 * 输出：0
 * 解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 * 
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int minDistince = 0xffff;
        int res = 0;
        for(int i =0;i<n-2;++i){
            int x = nums[i];

            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int ans = x + nums[j] + nums[k];
                if(ans > target){
                    k--;
                }else if(ans < target){
                    j++;
                }else{
                    return target;
                }
                int distince = abs(target - ans);
                if(distince < minDistince){
                    minDistince = distince;
                    res = ans;
                }
            }

        }

        return res;
    }
};
// @lc code=end

