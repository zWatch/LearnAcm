/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (39.68%)
 * Likes:    1106
 * Dislikes: 0
 * Total Accepted:    133.2K
 * Total Submissions: 335.7K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
#include <string>
#include <stack>
#include <vector>
#include <array>
using namespace std;
class Solution {
public:
	int encode[128];

	Solution() {
		encode['(']=1;
		encode['[']=2;
		encode['{']=3;
		encode[')']=-1;
		encode[']']=-2;
		encode['}']=-3;
	}
	
	inline int getEnCode(char s) {
		return encode[s];
	}

public:
	bool isValid(string s) {

		stack<char> ss;
		//ss.clear();

		for (auto i = 0; i<s.length(); i++) {
			bool isEmpty = ss.empty();
			if (getEnCode(s[i])>0) {
				
				ss.push(s[i]);
				
				if (ss.size() > (s.length()+1)/2) {
					return false;
				}
			}
			else{
				if (ss.empty()) {
					return false;
				}
				if(getEnCode(ss.top())+getEnCode(s[i]) != 0){
					return false;
				}
				ss.pop();
			}
		}
		return ss.empty();
	}
};



// @lc code=end

