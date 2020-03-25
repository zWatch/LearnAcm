/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (48.16%)
 * Likes:    275
 * Dislikes: 0
 * Total Accepted:    84.7K
 * Total Submissions: 170.5K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto b=head;
        if(b==nullptr || b->next==nullptr){
            return b;
        }
        
        while(b!=nullptr && b->next!=nullptr){
            if(b->val==b->next->val){
                auto tmp=b->next;
                b->next=b->next->next;
                delete tmp;
            }else{
                b=b->next;
            }
        }
        return head;
    }
};
// @lc code=end

/*
if (h && (h->next = deleteDuplicates(h->next)) && h->next->val == h->val) delete h, h = h->next; return h;
*/