#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		map<int, int> mmp1;
		map<int, int> mmp2;
		for (auto& i: arr){
			mmp1[i]++;
		}

		for (auto var = mmp1.cbegin(); var != mmp1.cend(); ++var) {
			if (mmp2.find(var->second)!=mmp2.end()) {
				return false;
			}
			else {
				mmp2[var->second] = var->first;
			}
		}
		return true;
	}
};





#ifdef DEBUG_IN_MY_COMPUTER

int main() {
	Solution s;
	vector<int> t1{1, 2, 2, 1, 1, 3};
	vector<int> t2{ 1, 2};
	vector<int> t3{ -3, 0, 1,-3, 1, 1, 1, -3, 10, 0 };
	vector<int> ct4{};
	vector<int> ct5{ 1, 1 ,1};
	cout << s.uniqueOccurrences(t1)<< endl;;
	cout << s.uniqueOccurrences(t2)<< endl;;
	cout << s.uniqueOccurrences(t3)<< endl;;
	cout << s.uniqueOccurrences(ct4)<< endl;;
	cout << s.uniqueOccurrences(ct5)<< endl;;
	cout << "TFTTT"<< endl;;
	return 0;
}

#endif

/*
5205. 独一无二的出现次数 显示英文描述
用户通过次数741
用户尝试次数769
通过次数749
提交次数1093
题目难度Easy
给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。

如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。



示例 1：

输入：arr = [1,2,2,1,1,3]
输出：true
解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
示例 2：

输入：arr = [1,2]
输出：false
示例 3：

输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
输出：true


提示：

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000

*/