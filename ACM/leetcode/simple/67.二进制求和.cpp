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
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        //对齐
        //n->a(al-n) : b(n+bl-al)
        if(a.size()<b.size()){
            return addBinary(b, a);
        }
        int curr=0;
        int n=a.size();
        int m=b.size();

        for(int n=a.size()-1 ; 
            n+b.size()-a.size()>=0; 
            n--
        ){
            

        }

    }
};
// @lc code=end

