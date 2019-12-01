/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 *
 * https://leetcode-cn.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (59.12%)
 * Likes:    633
 * Dislikes: 0
 * Total Accepted:    102K
 * Total Submissions: 172.4K
 * Testcase Example:  '"III"'
 *
 * 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 * 
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V +
 * II 。
 * 
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数
 * 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 * 
 * 
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 
 * 
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 * 
 * 示例 1:
 * 
 * 输入: "III"
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: "IV"
 * 输出: 4
 * 
 * 示例 3:
 * 
 * 输入: "IX"
 * 输出: 9
 * 
 * 示例 4:
 * 
 * 输入: "LVIII"
 * 输出: 58
 * 解释: L = 50, V= 5, III = 3.
 * 
 * 
 * 示例 5:
 * 
 * 输入: "MCMXCIV"
 * 输出: 1994
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * 
 */

// @lc code=start
#include <string>
using namespace std;
#define ROM_I 1
#define ROM_V 5
#define ROM_X 10
#define ROM_L 50
#define ROM_C 100
#define ROM_D 500
#define ROM_M 1000
#define ROM_IV 4
#define ROM_IX 9
#define ROM_XL 40
#define ROM_XC 90
#define ROM_CD 400
#define ROM_CM 900

class Solution {
public:
    int romanToInt(string s) {
        
		int sum = 0;
		for (int i=0; i<s.length(); i++) {
			switch (s[i])
			{
			case 'I':
				if (s[i+1]=='V') {
					sum+=ROM_IV;
					i++;
				}
				else if (s[i + 1] == 'X') {
					sum += ROM_IX;
					i++;
				}
				else {
					sum += ROM_I;
				}
				break;
			case 'V':
				sum += ROM_V;
				break;
			case 'X':
				if (s[i + 1] == 'L') {
					sum += ROM_XL;
					i++;
				}
				else if (s[i + 1] == 'C') {
					sum += ROM_XC;
					i++;
				}
				else {
					sum += ROM_X;
				}
				break;
			case 'L':
				sum += ROM_L;
				break;
			case 'C':
				if (s[i + 1] == 'D') {
					sum += ROM_CD;
					i++;
				}
				else if (s[i + 1] == 'M') {
					sum += ROM_CM;
					i++;
				}
				else {
					sum += ROM_C;
				}
				break;
			case 'D':
				sum += ROM_D;
				break;
			case 'M':
				sum += ROM_M;
				break;
			default:
				break;
			}
		}
		return sum;
    }
};
// @lc code=end

