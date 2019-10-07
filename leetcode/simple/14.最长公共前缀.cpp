/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.91%)
 * Likes:    718
 * Dislikes: 0
 * Total Accepted:    130.5K
 * Total Submissions: 373.8K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	inline int prefix(const string& a, const string& b, int m) {
		for (int i=0; i<m; i++) {
			if (a[i]!=b[i]) {
				return i;
			}
		}
		return m;
	}


	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size()==0) {
			return "";
		}else if (strs.size()==1) {
			return strs[0];
		}
		int min_prefix = numeric_limits<int>::max();

		for (auto& iter: strs){
			min_prefix = min((int) iter.length(), min_prefix);
		}
		if (min_prefix==0) {
			return "";
		}

		string firstPrefix=strs[0];
		//binary_search();
		for (int i = 0; i < strs.size() - 1; i++) {
			min_prefix = prefix(strs[i], strs[i+1], min_prefix);
			///*
			if(min_prefix==0){
				return "";
			}
            //*/
		}
		return strs[0].substr(0, min_prefix);
	}
};
// @lc code=end

