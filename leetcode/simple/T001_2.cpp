#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:

	vector<int> twoSum(vector<int>& nums, int target) {
		int i = 0;
		auto iter = nums.begin();
		auto pos = nums.end();
		for (; iter != nums.end(); iter++){
			pos = find(iter + 1, nums.end(), target - *iter);
			if (pos != nums.end()) {
				break;
			}
		}
		
		return vector<int>{(int)(iter - nums.begin()), (int)(pos - nums.begin())};
	}
};
