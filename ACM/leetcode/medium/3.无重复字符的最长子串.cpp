/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (31.59%)
 * Likes:    2499
 * Dislikes: 0
 * Total Accepted:    231.5K
 * Total Submissions: 733K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int minPos[128];

    int lengthOfLongestSubstring(string s) {
        int ret=0;
        memset(minPos, -1, sizeof(minPos));
        int max_same=0;

        for(int i=0; i<s.size(); i++){
            char cs=s[i];
            max_same=max(minPos[cs]+1, max_same);
            minPos[cs]=i;
            ret=max(i-max_same+1, ret);
            //if find min(cs_pos, max_same);
            //length
        }
        return ret;
    }
};
// @lc code=end

