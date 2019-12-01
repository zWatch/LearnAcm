/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (47.63%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    49.6K
 * Total Submissions: 104K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode Top{0};
        ListNode* ret=&Top;
        multimap<int , ListNode*> ml;
        for_each(lists.cbegin(), lists.cend(), [&](ListNode* l){
            if(l!=nullptr){
                ml.insert(make_pair(l->val, l));
            }
        });

        for(auto iter=ml.begin(); iter!=ml.end(); iter=ml.begin()){
            auto l=iter->second;
            ret->next=l;
            ret=ret->next;
            ml.erase(iter);
            if(l->next!=nullptr){
                ml.insert(make_pair(l->next->val, l->next));
                ml.emplace();
            }
        }
        return Top.next;
    }
};
// @lc code=end
//t90 s80
int main(){
    Solution s;
    //std::cout<<<<std::endl
    return 0;
}

