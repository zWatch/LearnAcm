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
����һ����̬�滮���⣺
[ A  B  C  D  E]
[]
����:
[ 1  2  3  4  5 ]

[ 1             ]
[               ]
[               ]

L[i]= L[i-1] 

Le[i] = []


*/


/*
��������������ͬ���ַ�����s �� t��

�� s �еĵ� i ���ַ��䵽 t �еĵ� i ���ַ���Ҫ |s[i] - t[i]| �Ŀ�������������Ϊ 0����Ҳ���������ַ��� ASCII ��ֵ�Ĳ�ľ���ֵ��

���ڱ���ַ��������Ԥ���� maxCost����ת���ַ���ʱ���ܿ���Ӧ��С�ڵ��ڸ�Ԥ�㣬��Ҳ��ζ���ַ�����ת�������ǲ���ȫ�ġ�

�������Խ� s �����ַ���ת��Ϊ���� t �ж�Ӧ�����ַ������򷵻ؿ���ת������󳤶ȡ�

��� s ��û�����ַ�������ת���� t �ж�Ӧ�����ַ������򷵻� 0��



ʾ�� 1��

���룺s = "abcd", t = "bcdf", cost = 3
�����3
���ͣ�s �е� "abc" ���Ա�Ϊ "bcd"������Ϊ 3��������󳤶�Ϊ 3��
ʾ�� 2��

���룺s = "abcd", t = "cdef", cost = 3
�����1
���ͣ�s �е���һ�ַ�Ҫ���� t �ж�Ӧ���ַ����俪������ 2����ˣ���󳤶�Ϊ 1��
ʾ�� 3��

���룺s = "abcd", t = "acde", cost = 0
�����1
���ͣ����޷������κθĶ���������󳤶�Ϊ 1��


��ʾ��

1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s �� t ��ֻ��СдӢ����ĸ��
*/