/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (54.87%)
 * Likes:    289
 * Dislikes: 0
 * Total Accepted:    25.4K
 * Total Submissions: 46.3K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 示例 :
 * 
 * 给定这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 说明 :
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <stack>
#include <bitset>
#include <string>
#include <algorithm>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode Top{0};
        ListNode* cur=&Top;
        ListNode* next=head;
        cur->next=next;

        ListNode* *s=new ListNode*[k];
        for(int i=0; i<k; i++){
            s[i]=nullptr;
        }
    
        for(;next!=nullptr;){
            for(int i=0; i<k && next!=nullptr; i++){
                s[i]=next;
                next=next->next;
            }
            if(s[k-1]!=nullptr){
                for(int i=0; i<k; i++){
                    cur->next=s[k-i-1];
                    s[k-i-1]=nullptr;
                    cur=cur->next;
                }
                cur->next=next;
            }else{
                goto End;
            }
        }
        End:
        return Top.next;
    }
};
// @lc code=end
//t70 s60

int main(){
    Solution s;
    //std::cout<<<<std::endl
    return 0;
}

