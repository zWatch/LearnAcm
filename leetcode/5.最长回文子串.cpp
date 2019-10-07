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
#include <string>
#include <algorithm>
using namespace std;
#define UN_POINT2(p, y, x, w) *(p+(x)+(y)*(w))

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0){
            return "";
        }
        if(s.size()==1){
            return s;
        };
        int ret_start=0;
        //int ret_end=0;
        int ret_length=0;
        /*
        char** dp=(char**)new char[s.size()*s.size()];
        int d=0;
        for(int i=0; i<s.size()-d; i++){
            dp[i][i+d]=1;
        }
        d=1;
        for(int i=0; i<s.size()-d; i++){
            if(s[i]==s[i+1])
                dp[i][i+d]=1;
        }
        
        for(d=2; d<s.size(); d++){
            for(int i=0; i<s.size()-d; i++){
                if(s[i]==s[i+1] && dp[i+1][i+d-1])
                    dp[i][i+d]=1;
            }
        }
        */
       
        /*
        char** dp=(char**)new char[s.size()*s.size()];
        int d=0;
        for(int i=0; i<s.size()-d; i++){
            dp[i][i+d]=1;
            ret_start=i;
            ret_end=i+d;
        }
        d=1;
        for(int i=0; i<s.size()-d; i++){
            if(s[i]==s[i+1]){
                dp[i][i+d]=1;
        
                ret_start=i;
                ret_end=i+d;
            }
        }
        
        for(d=2; d<s.size(); d++){
            bool hasChange=false;
            for(int i=0; i<s.size()-d; i++){
                if(s[i]==s[i+1] && dp[i+1][i+d-1]){
                    dp[i][i+d]=1;

                    ret_start=i;
                    ret_end=i+d;
                    
                    hasChange=true;
                }
            }
            if(hasChange==false){
                break;
            }
        }
        */
        //return d-1;
        char* dp=new char[s.size()*s.size()];
        int d=0;
        for(int i=0; i<s.size()-d; i++){
            //dp[i][i+d]=1;
            UN_POINT2(dp, i, i+1, s.size()) = 1;
            ret_start=i;
            ret_length=d+1;
        }
        d=1;
        for(int i=0; i<s.size()-d; i++){
            if(s[i]==s[i+1]){
                //dp[i][i+d]=1;
                UN_POINT2(dp, i, i+d, s.size())=1;
                ret_start=i;
                ret_length=d+1;
            }
        }
        
        for(d=2; d<s.size(); d++){
            bool hasChange=false;
            for(int i=0; i<s.size()-d; i++){
                if(
                s[i]==s[i+1] 
                //&& dp[i+1][i+d-1]
                && UN_POINT2(dp, i+1, i+d-1, s.size())
                ){
                    //dp[i][i+d]=1;
                    UN_POINT2(dp, i, i+d, s.size())=1;
                    ret_start=i;
                    ret_length=d+1;
                    
                    hasChange=true;
                }
            }
            if(hasChange==false){
                break;
            }
        }

        return s.substr(ret_start, ret_length);
    }
};
// @lc code=end

/*
dp[i][i]=1
dp[i][i+1]=1 if(s[i]=s[i+1])
dp[i][i+d]=1 if(s[i]=s[i+d] && dp[i+1][i+d-1])

d is max loop

break point is d=k, any(dp[i][i+k] != 0) when i:(any) ;
answer is k-1

time is O(n^2)
space is O(n^2)
*/
int main(){
    


}


