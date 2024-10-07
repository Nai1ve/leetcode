/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
 *
 * https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
 *
 * algorithms
 * Medium (51.69%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    10.1K
 * Total Submissions: 19.5K
 * Testcase Example:  '[1,3,2,3,3]\n2'
 *
 * 给你一个整数数组 nums 和一个 正整数 k 。
 * 
 * 请你统计有多少满足 「 nums 中的 最大 元素」至少出现 k 次的子数组，并返回满足这一条件的子数组的数目。
 * 
 * 子数组是数组中的一个连续元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,2,3,3], k = 2
 * 输出：6
 * 解释：包含元素 3 至少 2 次的子数组为：[1,3,2,3]、[1,3,2,3,3]、[3,2,3]、[3,2,3,3]、[2,3,3] 和
 * [3,3] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,4,2,1], k = 3
 * 输出：0
 * 解释：没有子数组包含元素 4 至少 3 次。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 * 1 <= k <= 10^5
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <ranges>
#include <algorithm>

using namespace std;
// 该方法运行超时
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int maxValue = 0;
        unordered_map<int,int> numCountMap;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            maxValue = max(maxValue,nums[i]);
            numCountMap[nums[i]] += 1;
        }

        int maxValueCount = numCountMap[maxValue];

        if(maxValueCount < k){
            return 0;
        }


        for(int left = 0;left < n;left++){
            int right = n - 1;
            
            if(left&&nums[left-1]==maxValue){
                maxValueCount--;
            }
            
            int tmpMaxValueCount = maxValueCount;
            while(tmpMaxValueCount >=k&&right-left + 1 >= k&&right >= left){
                // 移动right的
                if(tmpMaxValueCount >= k){
                    res++;
                }
                if(nums[right] == maxValue){
                    tmpMaxValueCount--;
                }
                right--;
            }
        }

        return res;
    }
};

class Solution1 {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int maxValue = std::ranges::max(nums);

        int count_maxValue = 0;
        int n = nums.size();
        int left = 0;
        for(int right = 0;right<n;right++){
            if(nums[right] == maxValue)
                count_maxValue++;
            while(count_maxValue==k){
                if(nums[left] == maxValue)
                    count_maxValue--;
                left++;
            }
            res += left;
        }

        return res;
    }
};
// @lc code=end

