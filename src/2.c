#include <stdlib.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int plus = 0, sum;

	struct ListNode *answer = calloc(1, sizeof(struct ListNode));;
	struct ListNode *curr = answer;

	curr->next = l1;
	while (l1 != NULL || l2 != NULL) {
		if (l1 == NULL) {
			l1 = calloc(1, sizeof(struct ListNode));
			curr->next = l1;
			l1->val = 0;
		} else if (l2 == NULL) {
			l2 = calloc(1, sizeof(struct ListNode));
			l2->val = 0;
		}

		sum = l1->val + l2->val + plus;
		plus = sum / 10;
		l1->val = sum % 10;

		l1 = l1->next;
		l2 = l2->next;
		curr = curr->next;
	}

	if (plus != 0) {
		l1 = calloc(1, sizeof(struct ListNode));
		curr->next = l1;
		l1->val = plus;
	}
	
	return answer->next;
}
