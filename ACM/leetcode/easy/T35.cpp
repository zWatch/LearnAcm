/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (44.32%)
 * Likes:    330
 * Dislikes: 0
 * Total Accepted:    78.1K
 * Total Submissions: 176.2K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 你可以假设数组中无重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,6], 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,3,5,6], 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 输入: [1,3,5,6], 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 输入: [1,3,5,6], 0
 * 输出: 0
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:

    template<class T_iter, typename T_Value>
    int binary_search_pos(T_iter first, T_iter last, T_Value value){
        auto low=first;
        auto high=last;
        auto target=value;
        while (low < high)
        {
            auto middle = low + (high - low) / 2;
            if (target == *middle)
            {
                return middle-first;
            }
            else if (target > *middle)
            {
                low = middle+1;
            }
            else if (target < *middle)
            {
                high = middle-1;
            }
        }

        for(; low<last && *low<target; low++){};
        return low-first;
    }

    int searchInsert(vector<int>& nums, int target) {
        return binary_search_pos(nums.begin(), nums.end(), target);
        //return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }

};
// @lc code=end

/*
62/62 cases passed (8 ms)
Your runtime beats 64.66 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.1 MB)
*/

/* other better
    
    //return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    
    auto first = nums.begin(), last = nums.end();
        while (first < last) {
            auto mid = first + ((last - first) >> 1);
            if (*mid < target) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        return first - nums.begin();
*/
