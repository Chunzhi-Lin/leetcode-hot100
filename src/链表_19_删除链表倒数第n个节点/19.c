#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode *fast = head, *slow = head, *prev = head;

	int tmp = n - 1;
	while (tmp--) {
		fast = fast->next;
	}

	while (fast->next != NULL) {
		prev = slow;
		fast = fast->next;
		slow = slow->next;
	}

	if (prev == slow) {
		return head->next;
	}

	prev->next = slow->next;

	return head;
}