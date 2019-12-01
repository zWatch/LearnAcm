/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	/*
	 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        else if (l2 == NULL) {
            return l1;
        }
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }

		while(){
			auto small= l1->val<l2->val?l1:l2;
			auto big=l1->val>=l2->val?l1:l2;
			
			while(small->next!=nullptr){
				if(small->next->val>val){
					ret_w1=small;
				}
			}
			auto temp_sort=small->next;
			small->next=big;
			
			small=big; 

			big=temp_sort;
			if(big=nullptr){
				break;
			}
		}

    }
	*/


public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1==nullptr) {
			return l2;
		}else if (l2==nullptr) {
			return l1;
		}

		ListNode*  small=nullptr;
		ListNode*  big = nullptr;
		ListNode* ret=nullptr;
		if(l1->val < l2->val){
			ret=small=l1;
			big=l2;
		}else{
			ret=small=l2;
			big=l1;			
		}
		while(true){
					
			while(small->next!=nullptr){
				if(small->next->val> big->val ){
					break;
				}
			}
			std::swap(small, big);
			big=big->next;	
			/*
				auto temp_sort=small->next;
				small->next=big;
				small=big;
				big=temp_sort;
			*/

			if(big=nullptr){
				break;
			}
		}
		return ret;
	}
};




/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/