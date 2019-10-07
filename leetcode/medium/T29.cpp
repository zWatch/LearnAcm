

#include <iostream>
#include <cstdlib>
//#include <math>
#include <cmath>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		
		if (divisor==1 ) {
			return dividend;
		}
		else if (divisor == -1) {
			if (dividend == (1 << 31)) {
				return ~(1 << 31);
			}
			return -dividend;
		}else if(divisor==0){
			return ~(1 << 31);
		}else if (divisor == (1<<31)) {
			return dividend == divisor;
		}


		bool flag2 = dividend==(1<<31);
		bool flag = (dividend > 0 ) == (divisor > 0);
		auto dividend2 = 0;
		auto divisor2 = 0;

		if (flag2) {
			if (flag) {
				dividend2 = abs(dividend- divisor);
				divisor2 = abs(divisor);
			}
			else{
				dividend2 = abs(dividend + divisor);
				divisor2 = abs(divisor);
			}
		}
		else{
			dividend2 = abs(dividend);
			divisor2 = abs(divisor);
		}


		int shang = 0;
		
		for (int j = 30; j>=0 ; j--) {
			shang <<= 1;
			if (dividend2>>j  >= divisor2) {
				dividend2 -= divisor2<<j;
				shang |= 1;
			}
		}
		if (flag) {
			return  shang + flag2;
		}
		else {
			return -shang - flag2;
		}
		return flag ? shang: -shang;
	}
};


#ifdef DEBUG_IN_MY_COMPUTER

int main() {
	Solution s;
	cout << (1 << 31) << endl;;
	cout << s.divide(10, 3) << endl;;
	cout << s.divide(10, 0) << endl;;
	cout << s.divide(10, -1) << endl;;
	cout << s.divide(1<<31, -1) << endl;;
	cout << s.divide(1<<31, 0) << endl;;
	cout << s.divide(1<<31, 2) << endl;;
	cout << s.divide(7, -3) << endl;;
	cout << s.divide(7, 3) << endl;;
	return 0;
}

#endif

//+-*/%^|&

/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
说明:

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/