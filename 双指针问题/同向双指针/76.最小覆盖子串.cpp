/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (46.33%)
 * Likes:    3016
 * Dislikes: 0
 * Total Accepted:    649.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 *
 *
 *
 * 注意：
 *
 *
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 *
 *
 *
 * 提示：
 *
 *
 * ^m == s.length
 * ^n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
 */

// @lc code=start
#include <string>

using namespace std;
class Solution {
    bool is_covered(int cnt_s[],int cnt_t[]){
        for(int i = 'A';i<='Z';i++){
            if(cnt_s[i] < cnt_t[i]){
                return false;
            }
        }

        for(int i = 'a';i<='z';i++){
            if(cnt_s[i] < cnt_t[i]){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int n_s = s.length();
        int ans_left =  -1;
        int ans_right = n_s;

        int cnt_s[128]{};
        int cnt_t[128]{};

        for(char c : t){
            cnt_t[c]++;
        }

        int left = 0;

        for(int right = 0;right < n_s;right++){
            cnt_s[s[right]]++;
            while(is_covered(cnt_s,cnt_t)){
                if(right - left < ans_right - ans_left){
                    ans_left = left;
                    ans_right = right;
                }
                cnt_s[s[left]]--;
                left++;
            }
        }

        return ans_left < 0? "":s.substr(ans_left,ans_right - ans_left + 1);
    }
};
// @lc code=end
