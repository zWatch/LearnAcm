﻿#include <map>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
class Solution {
	

public:
	
	Solution() {
	
	
	}

	int climbStairs(int n) {
	
	}
	//C(i, j)=j!/(i! *(j-i)!)

};




#ifdef DEBUG_IN_MY_COMPUTER

int main() {
	Solution s;
	vector<int> t1{-2,1,-3,4,-1,2,1,-5,4};
	vector<int> t2{ 1, 2 };
	vector<int> t3{ -3, 0, 1,-3, 1, 1, 1, -3, 10, 0 };
	vector<int> ct4{};
	vector<int> ct5{ 1, 1 ,1 };
	cout << s.maxSubArray(t1) << endl;;
	return 0;
}

#endif


/*
选则为1
不选则为0

*/






/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

*/
