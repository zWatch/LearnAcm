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
			//这里，取消掉之后更快（大概是测试样本的问题）
			//*/
		}
		return strs[0].substr(0, min_prefix);
	}
};