/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode.cn/problems/4sum/description/
 *
 * algorithms
 * Medium (36.61%)
 * Likes:    1962
 * Dislikes: 0
 * Total Accepted:    627.7K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a],
 * nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 * 
 * 
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * 
 * 
 * 你可以按 任意顺序 返回答案 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(int i = 0;i<n - 3;++i){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int x = nums[i];
            for(int j = i+1;j<n - 2;++j){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int y = nums[j];
                int k = j + 1;
                int l = n - 1;

                while(k < l){
                    long sum = (long)x + y + nums[k] + nums[l];

                    if(sum == target){
                        res.push_back({x,y,nums[k],nums[l]});
                        for(k++;k<l&&nums[k] == nums[k-1];k++) continue;
                        for(l--;l>k&&nums[l] == nums[l+1];l--) continue;
                    }else if(sum < target){
                        k++;
                    }else if(sum > target){
                        l--;
                    }
                }

            }
        }
        return res;
    }
};
// @lc code=end

