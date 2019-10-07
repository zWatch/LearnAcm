#include <iostream>

using namespace std;
class Solution {
public:
	int reverse(int x) {
		if (x==(1<<31)) {
			//-2147483648
			return 0;
		}
		bool flag = x >= 0;
		x = std::abs(x);//转换成整数防止负数的计算超出预期

		char Number[12];//2^32 ~= 4*10^3*3
		int nl = 0;
		int ret = 0;
		for (; x != 0; x/=10) {
			Number[nl++] = x%10;//地位在前
		}

		for (int j = 0; j<nl; j++) {
			long nRet = ret*10;
			nRet += Number[j];
			//if (nRet< ret) {  //change because 溢出竟然抛出错误我也是很服气的
			if (nRet>= 2147483648) {
				return 0;
			}
			ret = nRet;
		}
		return flag?ret:-ret;
	}
};


/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/