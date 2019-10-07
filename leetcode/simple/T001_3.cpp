#include <algorithm>
#include <vector>
using namespace std;
//错误原因：将nums重排序了
class Solution {
public:
	
	vector<int> twoSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int posI=0;
		int posJ=nums.size()-1;
		for (; posI < nums.size() - 1; posI++) {//之所以减1是因为必定有解
			auto vec = nums[posI] + nums[posJ] < target;
			if (vec) {
				for (; posJ < nums.size(); posJ++) {
					if ((nums[posI] + nums[posJ]) == target) {
						goto Out;
					}
					else if ((nums[posI] + nums[posJ]) > target) {
						break;
					}
				}
				posJ--;
			}
			else {
				for (; posJ > posI; posJ--) {
					if ((nums[posI] + nums[posJ]) == target) {
						goto Out;
					}
					else if ((nums[posI] + nums[posJ]) < target) {
						//break;
						goto Lab2;
					}
				}
				break;//posJ++;//this mean no answer
			Lab2:;
			};
		}
		Out:
		return vector<int>{posI, posJ};
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
