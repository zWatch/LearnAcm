/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (52.75%)
 * Likes:    320
 * Dislikes: 0
 * Total Accepted:    51.2K
 * Total Submissions: 97.1K
 * Testcase Example:  '1'
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 
 * 注意：整数顺序将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
constexpr static int max_n=30;
    
class Solution {
    std::vector<string> cache{max_n};
public:
    Solution(){
        cache[0]="1";
        char as[3];
            as[2]=0;
            
        for(int i=1; i<30; i++){
            int newStringPos=0;
            for(int j=0; j<cache[i-1].size(); ){
                int l=j;
                as[1]=cache[i-1][j];
                for(l++ ; l<cache[i-1].size() && as[1]==cache[i-1][l]; l++);
                as[0]='0'+l-j;
                cache[i].append(as);
                j=l;
            }
        }
    }


    string countAndSay(int n) {
        return cache[n-1];
    }
};
// @lc code=end

