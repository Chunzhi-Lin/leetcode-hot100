#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *tmp;

	head->next->next = swapPairs(head->next->next);
	tmp = head->next;
	head->next = head->next->next;
	tmp->next = head;

	return tmp;
}