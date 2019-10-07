

#include <map>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
class Solution {
public:


	int maxSubArray(vector<int>& nums) {
		
		//hack for time
		if (nums.size()==1) {
			return nums[0];
		}
		int ret = nums[0];
		int sum = nums[0];
		for (auto i = 1; i<nums.size(); ++i) {
			sum = (sum > 0) ? sum+nums[i]: nums[i];
			ret = max(ret, sum);
		}
		return ret;


		/*
		int ret = nums[0];
		int sum = 0;
		for (auto i : nums){
			if(sum<0) {
				sum = i;
			}
			else {
				sum += i;
			}
			ret = max(ret, sum);
		}
		return ret;
		*/
		
		/*
		int ret = nums[0];
		int sum = 0;
		for(auto i: nums){
			sum += i;
			if (sum<0) {
				sum = 0;
			}
			else {
				ret = max(ret, sum);
			}
		}
		return ret;
		*/
	}


	/*
		isL :
			1<<0 左
			1<<1 右
			1<<2 中
	*/
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
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/
