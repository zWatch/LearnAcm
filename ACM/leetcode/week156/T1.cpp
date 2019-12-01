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
5205. ��һ�޶��ĳ��ִ��� ��ʾӢ������
�û�ͨ������741
�û����Դ���769
ͨ������749
�ύ����1093
��Ŀ�Ѷ�Easy
����һ���������� arr�������æͳ��������ÿ�����ĳ��ִ�����

���ÿ�����ĳ��ִ������Ƕ�һ�޶��ģ��ͷ��� true�����򷵻� false��



ʾ�� 1��

���룺arr = [1,2,2,1,1,3]
�����true
���ͣ��ڸ������У�1 ������ 3 �Σ�2 ������ 2 �Σ�3 ֻ������ 1 �Ρ�û���������ĳ��ִ�����ͬ��
ʾ�� 2��

���룺arr = [1,2]
�����false
ʾ�� 3��

���룺arr = [-3,0,1,-3,1,1,1,-3,10,0]
�����true


��ʾ��

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000

*/