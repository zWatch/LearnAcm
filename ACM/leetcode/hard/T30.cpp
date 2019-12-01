/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (27.41%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    15.8K
 * Total Submissions: 57.4K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 *  
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <stack>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        vector<long long> words_pos{(int)words.size(), -1};
        if(words.size()==0){
            return vector<int>(0);
        }
        if(words.size()==1){
            for(auto iter=s.find(words[0], 0); iter!=s.npos; iter=s.find(words[0], iter+1)){
                ret.push_back(iter);
            }   
            return ret;
        }


        
        bool end=false;
        while(!end){
            long long max=-1;
            long long min=-1;


        }

    }
};
// @lc code=end
int main(){
    Solution s;
    //std::cout<<<<std::endl
    return 0;
}

