#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *mergelist (struct ListNode *head1, struct ListNode *head2)
{
	struct ListNode *dummy = malloc(sizeof(struct ListNode));
	struct ListNode *temp = dummy, *temp1 = head1, *temp2 = head2;

	while (temp1 != NULL && temp2 != NULL) {
		if (temp1->val < temp2->val) {
			temp->next = temp1;
			temp1 = temp1->next;
		} else {
			temp->next = temp2;
			temp2 = temp2->next;
		}

		temp = temp->next;
	}

	temp->next = temp1 ? temp1 : temp2;

	struct ListNode *result = dummy->next;
	free(dummy);  // 释放dummy节点
	return result;
}

struct ListNode* sortList(struct ListNode* head)
{
#if 0
/* 快排+递归 */
	if (head == NULL || head->next == NULL)
		return head;

	struct ListNode *dummy0 = calloc(1, sizeof(struct ListNode));
	struct ListNode *dummy1 = calloc(1, sizeof(struct ListNode));
	struct ListNode *dummy2 = calloc(1, sizeof(struct ListNode));
	struct ListNode *curr = head, *left = NULL, *right = NULL, *same = NULL;
	struct ListNode *fast = head, *slow = head;

	while (fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}

	int same_val = slow->val;

	left = dummy0;
	right = dummy1;
	same = dummy2;

	while (curr != NULL) {
		if (curr->val < same_val) {
			left->next = curr;
			left = left->next;
		} else if (curr->val > same_val) {
			right->next = curr;
			right = right->next;
		} else {
			same->next = curr;
			same = same->next;
		}

		curr = curr->next;
	}

	left->next = NULL;
	right->next = NULL;
	same->next = NULL;

	dummy0->next = sortList(dummy0->next);
	dummy1->next = sortList(dummy1->next);

	same->next = dummy1->next;

	struct ListNode *prehead = dummy0->next, *result;
	if (prehead == NULL) {
		result = dummy2->next;
	} else {
		result = prehead;
		left = prehead;
		while (left->next != NULL) {
			left = left->next;
		}
		left->next = dummy2->next;
	}

	free(dummy0);
	free(dummy1);
	free(dummy2);

	return result;
#elif 0
/* 自顶向下归并+递归 */
	if (!head || !head->next) return head;
	
	// 快慢指针找中点
	struct ListNode *slow = head, *fast = head->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	
	// 分割链表
	struct ListNode *mid = slow->next;
	slow->next = NULL;
	
	// 递归排序
	struct ListNode *left = sortList(head);
	struct ListNode *right = sortList(mid);
	
	// 合并两个有序链表
	struct ListNode dummy = {0, NULL};
	struct ListNode *tail = &dummy;
	
	while (left && right) {
		if (left->val < right->val) {
			tail->next = left;
			left = left->next;
		} else {
			tail->next = right;
			right = right->next;
		}
		tail = tail->next;
	}
	
	tail->next = left ? left : right;
	return dummy.next;

#else
/* 自底向上归并 */
	if (!head || !head->next) return head;

	int lenth = 0;
	struct ListNode *node = head;

	while (node != NULL) {
		node = node->next;
		lenth++;
	}

	struct ListNode *dummyhead = malloc(sizeof(struct ListNode));

	dummyhead->next = head;

	for (int step = 1; step < lenth; step *= 2) {
		struct ListNode *new_list_tail = dummyhead;
		struct ListNode *curr = dummyhead->next;

		while (curr != NULL) {
			struct ListNode *head1 = curr;
			struct ListNode *head2, *next = NULL;

			for (int i = 1; (i < step) && (curr->next != NULL); i++) {
				curr = curr->next;
			}

			head2 = curr->next;
			curr->next = NULL;

			curr = head2;

			for (int i = 1; (i < step) && curr != NULL && (curr->next != NULL); i++) {
				curr = curr->next;
			}

			if (curr != NULL) {
				next = curr->next;
				curr->next = NULL;
			}

			new_list_tail->next = mergelist(head1, head2);

			 while (new_list_tail->next) {
                		new_list_tail = new_list_tail->next;
 			}

			curr = next;
		}
	}

	return dummyhead->next;
#endif
}
