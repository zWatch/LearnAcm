/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (45.04%)
 * Likes:    419
 * Dislikes: 0
 * Total Accepted:    62.1K
 * Total Submissions: 137.8K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 * 5
 * A           A
 * A        A  A
 * A     A     A
 * A  A        A
 * A           A
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R   
 * 
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
    string convert(string s, int numRows) {
        //first : 0 each:(numRows*2-3):
        //second : 1 :  each:(numRows*2-3-1)  : 1+each:(numRows*2-3) :
        //third : 2 : each:(numRows*2-3)-j : 2+each:(numRows*2-3)
        if(s.size()<=numRows || numRows==1){
            return s;
        }
        string ret;
        ret.resize(s.size());
        ret.clear();
        //vector<char> buf;
        //ret.assign(buf.begin(), buf.end());
        auto G=numRows*2-2;
        for(int i=0; i<s.length(); i+=G){
            ret+=s[i];
        }
        for(int j=1; j<numRows-1; j++){
            auto i=j;
            while(i<s.size()){
                //if(){break;}
                ret+=s[i];
                i+=G-2*j;
                if(i>=s.size()){break;}
                ret+=s[i];
                i+=2*j;
            }
        }
        for(int i=numRows-1; i<s.length(); i+=G){
            ret+=s[i];
        }
        return ret;
    }
};
// @lc code=end

