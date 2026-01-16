#include <stdio.h>
#include <stdbool.h>

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

struct ListNode *main(struct ListNode *head) {
/* 快慢双指针 */
	if (head == NULL || head->next == NULL)
		return NULL;

	struct ListNode *slow = head, *fast = head, *ptr = head;
	
	while (true) {
		if (fast == NULL || fast->next == NULL)
			return NULL;

		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow)
			break;
	}

	while (ptr != slow) {
		ptr = ptr->next;
		slow = slow->next;
	}

	return slow;
}