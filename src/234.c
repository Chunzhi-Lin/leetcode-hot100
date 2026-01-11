#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

int main(struct ListNode* head)
{
#if 0
	int num = 0;
	int values[10^5 + 1];
	struct ListNode *node = head, *p;
	while (node != NULL) {
		values[num] = node->val;
		node = node->next;
		num++;
	}

	for (int i = 0; i < num / 2; i++) {
		if (values[i] != values[num - 1 - i])
			return false;
	}
	return true;
#else
	struct ListNode *fast = head, *slow = head, *pre, *curr, *next;

	if (head == NULL || head->next == NULL)
		return true;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	if (fast != NULL)
		pre = slow->next;
	else
		pre = slow;

	curr = pre;
	pre = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = pre;
		pre = curr;
		curr = next;
	}

	while (head != NULL && pre !=NULL) {
		if (head->val  != pre->val)
			return false;
		head = head->next;
		pre = pre->next;
	}

	return true;
		
#endif
}