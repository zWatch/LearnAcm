#include <map>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {

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
这是一个动态规划问题：
[ A  B  C  D  E]
[]
开销:
[ 1  2  3  4  5 ]

[ 1             ]
[               ]
[               ]

L[i]= L[i-1] 

Le[i] = []


*/


/*
给你两个长度相同的字符串，s 和 t。

将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 |s[i] - t[i]| 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。

用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。

如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。

如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。



示例 1：

输入：s = "abcd", t = "bcdf", cost = 3
输出：3
解释：s 中的 "abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。
示例 2：

输入：s = "abcd", t = "cdef", cost = 3
输出：1
解释：s 中的任一字符要想变成 t 中对应的字符，其开销都是 2。因此，最大长度为 1。
示例 3：

输入：s = "abcd", t = "acde", cost = 0
输出：1
解释：你无法作出任何改动，所以最大长度为 1。


提示：

1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s 和 t 都只含小写英文字母。
*/