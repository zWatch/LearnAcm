#include <iostream>
#include <cmath>
using namespace std;


#ifdef DEBUG_IN_MY_COMPUTER

 struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

#endif
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		char aux = 0;
		ListNode top = ListNode(0);
		auto ret_iter = &top;
		while (l1!=nullptr && l2 !=nullptr) {
			
			auto ret_next = new ListNode((aux + l1->val + l2->val) % 10);
			aux = (aux+l1->val + l2->val)/10;
			ret_iter->next=ret_next;
			ret_iter = ret_next;
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode* n = l1 != nullptr ? l1: l2;
		while(n != nullptr) {
			
			auto ret_next = new ListNode((aux + n->val) % 10);
			aux = aux / 10;
			ret_iter->next = ret_next;
			ret_iter = ret_next;
			n = n->next;
		}
		while (aux){
			auto ret_next = new ListNode(aux % 10);
			aux = (aux + n->val) / 10;
			ret_iter->next = ret_next;
			ret_iter = ret_next;
		}

		ret_iter->next = nullptr;
		return top.next;
	}
};


#ifdef DEBUG_IN_MY_COMPUTER

int main() {
	Solution s;
	


	return 0;
}

#endif


/*

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

*/
