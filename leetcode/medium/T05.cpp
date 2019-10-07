


class Solution {
public:

};


#ifdef DEBUG_IN_MY_COMPUTER

int main() {
	Solution s;
	cout << (1 << 31) << endl;;
	cout << s.divide(10, 3) << endl;;
	cout << s.divide(10, 0) << endl;;
	cout << s.divide(10, -1) << endl;;
	cout << s.divide(1 << 31, -1) << endl;;
	cout << s.divide(1 << 31, 0) << endl;;
	cout << s.divide(1 << 31, 2) << endl;;
	cout << s.divide(7, -3) << endl;;
	cout << s.divide(7, 3) << endl;;
	return 0;
}

#endif

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

*/