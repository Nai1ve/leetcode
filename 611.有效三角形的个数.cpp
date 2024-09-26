/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 *
 * https://leetcode.cn/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (53.91%)
 * Likes:    581
 * Dislikes: 0
 * Total Accepted:    110.5K
 * Total Submissions: 205.1K
 * Testcase Example:  '[2,2,3,4]'
 *
 * 给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [2,2,3,4]
 * 输出: 3
 * 解释:有效的组合是: 
 * 2,3,4 (使用第一个 2)
 * 2,3,4 (使用第二个 2)
 * 2,2,3
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [4,2,3,4]
 * 输出: 4
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 * 
 * 
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // 三角形判断，两边之和大于第三边,两数和变式
        sort(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size();

        for(int i = n -1;i>1;i--){
            int p = 0;
            int q = i - 1;
            while(p < q){
                if(nums[i] < nums[p]+nums[q]){
                    // 此处为重点，容易直接递增，导致数据丢失，最小的和最大的和大于第三边，那么其中间的数据也是满足条件的不能丢弃
                    res+=q-p;
                    q--;
                }else{
                    p++;
                }
            }

        }

        return res;
    }
};
// @lc code=end

