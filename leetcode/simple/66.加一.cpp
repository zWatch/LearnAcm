/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (41.13%)
 * Likes:    354
 * Dislikes: 0
 * Total Accepted:    81.7K
 * Total Submissions: 198.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //int curr=1;
        if(digits.size()==0){
            return vector(1, 1);
        }
        //auto ret(digits);
        auto& ret=digits;
        int i=ret.size()-1;
        do{
            ret[i]=(ret[i]+1)%10;
            if(ret[i] != 0){
                break;
            }
            i--;
        }while(i>=0);
        if(i<0) ret.insert(ret.begin(), 1);
        return ret;
    }
};
// @lc code=end

