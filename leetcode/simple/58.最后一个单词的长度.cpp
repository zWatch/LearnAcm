/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (31.18%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    45.3K
 * Total Submissions: 145.2K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
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
 using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {


        int lastWord_end=s.size();
        int lastWord_start=s.size();
        
        for(lastWord_end=s.size()-1; lastWord_end>=0 && s[lastWord_end]==' ' ;lastWord_end--);
        for(lastWord_start=lastWord_end; lastWord_start>=0 && s[lastWord_start]!=' ' ;lastWord_start--);
        return lastWord_end-lastWord_start;
    }
};
// @lc code=end

