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
#include <list>
#include <map>
#include <stack>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0){
            return "";
        }

        decltype(s.size()) ret_start=0;
        decltype(s.size()) ret_length=1;
        //vector<bitset<1000>> dp;
        bitset<1000*1000> dp;
        
        dp[0]=1;
        for(int i=1; i<s.size(); i++){
            dp[i*s.size()+i] = 1;
            if(s[i]==s[i-1]){
                dp[i*s.size()+i-1]=1;
                ret_start=i-1;
                ret_length=2;
            }
            //else{
            //    dp[i+1][i]=0;
            //}
        }
        
        for(int i=2; i<s.size(); i++){
            
            for(int j=0; j<i-1; j++){
                if(s[i]==s[j] && dp[(i-1)*s.size()+j+1]==1){
                    dp[i*s.size()+j]=1;
                     if(ret_length<i-j+1){
                        ret_start=j;
                        ret_length=i-j+1;
                        if(ret_length==s.size()){
                            goto ans;
                        }
                    }
                    
                }
                //else{
                //  dp[i][j]=0;
                //}
               
            }
        }
        ans:
        return string(s.substr(ret_start, ret_length));
    }
};
// @lc code=end
/*
vector<vector<int>> dp;
        dp.resize(s.size());
        for(int i=0; i<s.size()-1; i++){
            dp[i].resize(i+1);
            dp[i][i]= 1;
            if(s[i]==s[i+1]){
                dp[i+1][i]=1;
            }
            //else{
            //    dp[i+1][i]=0;
            //}
        }
        dp[s.size()-1].resize(s.size());
        dp[s.size()-1][s.size()-1]= 1;

        for(int i=2; i<s.size(); i++){
            for(int j=0; j<i; j++){
                if(s[i]==s[j] && dp[i-1][j+1]==1){
                    dp[i][j]=1;   
                }
                //else{
                //  dp[i][j]=0;
                //}
            }
        }
*/
int main(){
    Solution s;
    std::cout<<s.longestPalindrome("aaaa")<<std::endl;
}