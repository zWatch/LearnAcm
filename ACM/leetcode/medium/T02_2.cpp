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
		//hack
		int aux = 0;
		ListNode top = ListNode(0);
		auto ret_iter = &top;
		ret_iter = l1 != nullptr ? l1 : l2 ;
		auto iter = l1;
		auto bitSum = 0;

		while (l1!=nullptr || l2 !=nullptr){

			if(l1){
				bitSum += l1->val;
				iter = l1;
				l1 = l1->next;
				ret_iter = ret_iter->next;
				if (l2) {
					bitSum += l2->val;
					iter = l2;
					l2 = l2->next;
				}
			}
			else if(l2){
				bitSum += l2->val;
				iter = l2;
				ret_iter = ret_iter->next;
				l2 = l2->next;
			}

			iter->val = bitSum % 10;
			bitSum = bitSum / 10;
			ret_iter->next = iter;
		}

		if (aux != 0) {
			ret_iter->next = new ListNode(bitSum);
		}
		return top.next;
	}
};


#ifdef DEBUG_IN_MY_COMPUTER

int main() {
	Solution s;
	ListNode a(5);
	ListNode b(5);


	auto ret= s.addTwoNumbers(&a, &b);

	for (auto iter=ret; iter!=nullptr; iter=iter->next) {
		cout << iter->val;
	}

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
