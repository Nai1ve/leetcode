/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (64.22%)
 * Likes:    5324
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre_height(n);
        pre_height[0] = height[0];

        for(int i=1;i<n;i++){
            pre_height[i] = max(pre_height[i-1],height[i]);
        }

        vector<int> sub_height(n);
        sub_height[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            sub_height[i] = max(sub_height[i+1],height[i]);
        }

        for(int i=0;i<n;i++){
            cout <<pre_height[i]<< ' ';
        }
        cout << endl;

        for(int i=0;i<n;i++){
            cout <<sub_height[i]<< ' ';
        }
        cout << endl;

        int res = 0;
        for(int i =0;i<n;i++){
            res += min(sub_height[i],pre_height[i]) - height[i];
        }
        return res;
    }
};

class Solution2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n -1;
        int pre_height = 0;
        int sub_height = 0;
        int res = 0;

        while(left < right){
            pre_height = max(pre_height,height[left]);
            sub_height = max(sub_height,height[right]);

            if(pre_height < sub_height){
                res += pre_height - height[left];
                left++;
            }else{
                res += sub_height - height[right];
                right--;
            }
        }

        return res;
    }
};

// @lc code=end

