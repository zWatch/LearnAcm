/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (24.94%)
 * Likes:    702
 * Dislikes: 0
 * Total Accepted:    33.4K
 * Total Submissions: 133.4K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * 
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 
 * 
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 * 
 * 
 * 示例 4:
 *  
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
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
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        //dp[i][j]=1, 字符串前i个字符匹配表达式前j个字符
        //dp[i][j+1]=1,  
            //1. 如果p[j+1]=='.' && dp[i-1][j] , //i>0
            //2. if(p(j+1)=='*') 
                    // 2.1: || dp[i][j-1]==1     x.length==0 
                    // 2.2: || dp[i][j]==1     x.length==1
                    //--// 2.3: || match(s(i), p(j)) && dp[i-1][j] x.length=='x'
            //3. match(s(i), p(j+1))


        //dp[i][j]=1,  
            //1. 如果p(j)=='.' && dp[i-1][j-1] , //i>0
            //2. if(p(j)=='*') 
                    // 2.1: || dp[i][j-2]==1     x.length==0 
                    // 2.2: || dp[i][j-1]==1     x.length==1
                    ////--// 2.3: ||dp[i-1][j] && match(s(i), p(j-1)) x.length=='x'
                    
            //3. match(s(i), p(j)) && dp[i-1][j-1]
            //match = s_c==p_c || p_c=='.'

        dp[0][1]= p[0]=='*';

        for (int j = 2; j <= n; j++) {
            //p(j)==p[j-1]
            if(p[j-1] == '*')
                dp[0][j]=dp[0][j-1]==1 || dp[0][j-2]==1;
        }
    
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                //p(j)==p[j-1]
                if(p[j-1] == '*'){
                    dp[i][j]=   dp[i][j-1] 
                                || dp[i][j-2]
                                || (dp[i-1][j] && (s[i-1]==p[j-2] || p[j-2]=='.'));
                }else{
                    //match(s(i), p(j))
                    //match = s_c==p_c || p_c=='.'
                    dp[i][j]= dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j -1]=='.');
                }
            }
        }
        return dp[m][n];
    }
    /* 正解
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        //bitset<_Any_tag> a();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
    */
};
// @lc code=end

int main(){
    Solution s;
    std::cout<<s.isMatch("acaabbaccbbacaabbbb", "a*.*b*.*a*aa*a*")<<std::endl;
    return 0;
}
