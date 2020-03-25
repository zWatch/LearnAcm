/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.34%)
 * Likes:    1345
 * Dislikes: 0
 * Total Accepted:    119.8K
 * Total Submissions: 438K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0){
            return 0;
        }
        //if s[i] - s[j] is 回文，则state[i][j]=true
        vector<vector<bool>> state(s.size(), vector<bool>(s.size(), false));
        fill(state[0].begin(), state[0].end(), true);

        for(int i=0; i<s.size()-1; i++){
            state[i][i+1]=(s[i]==s[i+1]);
        }

        for(int g=2; g<s.size(); g++){
            for(int i=0; i<s.size()-g; i++){
                state[i][i+g]=state[i+1][i+g-1] && (s[i]==s[i+g]);
            }
        }

        return "";
    }
};
// @lc code=end

