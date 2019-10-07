#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() == 0 && nums2.size()==0) return 0.0;

		if (nums1.size()==0){
			return Solution_Zero(nums1, nums2);
		}else if (nums2.size() == 0) {
			return Solution_Zero(nums2, nums1);
		}

		if (nums1[nums1.size()-1]<nums2[0]) {
			return Solution_One(nums1, nums2);
		}else if (nums2[nums2.size()-1]<nums1[0]) {
			return Solution_One(nums2, nums1);
		}
		return Solution_Two_tmp(nums1, nums2);
	}

	double Solution_Zero(vector<int>& a, vector<int>& b) {
		if (b.size() % 2 == 1) {
			return b[b.size() / 2];
		}else {
			return (b[b.size() / 2 -1] + b[b.size() / 2]) / 2.0;
		}
	}
	
	double Solution_One(vector<int>& a, vector<int>& b) {
		int la = a.size();
		int lb = b.size();
		if((la+lb)%2==1){
			int rpos = (la+lb)/2;
			if (rpos<la){
				return a[rpos];
			}
			else {
				return b[rpos-la];
			}
		}
		else {
			if (la==lb) {
				return (a[a.size()-1] + b[0]) / 2.0;
			}else {
				int Mm = (la + lb) / 2-1;
				int MM = (la + lb) / 2;
				if (MM<la){
					return (a[Mm] + a[MM]) / 2.0;
				}else {
					return (b[Mm-la] + b[MM-la]) / 2.0;
				}

			}
		}
	}

	double Solution_Two_tmp(vector<int>& a, vector<int>& b) {
		vector<int> newVec(a.size()+b.size());
		newVec.clear();

		int pb = 0;
		for_each(a.begin(), a.end()
			, [&](int s)->void {
				while(pb<b.size() && b[pb]<s) {
					newVec.push_back(b[pb]);
					pb++;
				}
				newVec.push_back(s);
			}
			);
		for (; pb < b.size(); pb++) {
			newVec.push_back(b[pb]);
		}


		if (newVec.size()%2==1) {
			return newVec[newVec.size() / 2];
		}
		else {
			return (newVec[newVec.size() / 2]+ newVec[newVec.size() / 2  -1])/2.0;
		}
	}
};



/*
思路：
分情况
0. 一个为空或两个为空

1. a数组中的元素全部比b数组的元素小

2. 部分交叉
	[ma, Ma]  MaInVb
	[mb, Mb]  mbInVa

	La Bb a&b


3. a数组完全包含b数组

实现：
按map
不使用map

*/

/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/