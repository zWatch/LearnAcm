﻿#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	
	vector<int> twoSum(vector<int>& nums, int target) {
		int i = 0;
		auto iter = nums.begin();
		auto pos = nums.end();
		for (;iter!=nums.end();iter++) {
			pos=find(iter+1, nums.end(), target-*iter);
			if (pos!=nums.end()){
				break;
			}
		}
		return vector<int>{(int)(iter-nums.begin()), (int)(pos - nums.begin())};
	}
};



//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
//
//示例 :
//
//给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回[0, 1]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/two-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
