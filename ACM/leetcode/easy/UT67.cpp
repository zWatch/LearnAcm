/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (50.83%)
 * Likes:    250
 * Dislikes: 0
 * Total Accepted:    41.9K
 * Total Submissions: 82.5K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        auto bString=(a.size()>b.size())?&a:&b;
        auto sString=(a.size()>b.size())?&b:&a;

        auto briter=bString->rbegin();
        auto sriter=sString->rbegin();

        bool aux=false;
        string ret;
        ret.reserve(bString->size());

        for(;
        briter!=bString->rend() && sriter!=sString->rend();
        briter++, sriter++
        ){
            auto tmp=(*briter-'0')+(*sriter-'0')+aux;
            aux=tmp/2;
            *briter=tmp%2+'0';
        }
        
        for(;
        briter!=bString->rend();
        briter++
        ){
            auto tmp=(*briter-'0')+aux;
            aux=tmp/2;
            *briter=tmp%2+'0';
        }
        
        if(aux){
            bString->insert(bString->begin(), '1');
        }
        return *bString;
    }
};
// @lc code=end

