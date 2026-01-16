#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode *tmp, *curr = head, *next, *prev;

	tmp = head;
	for (int i = 0; i < k; i++) {
		if (tmp == NULL)
			return head;
		tmp = tmp->next;
	}

	tmp = reverseKGroup(tmp, k);

	prev = tmp;
	for (int i = 0; i < k; i++) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	return prev;
}