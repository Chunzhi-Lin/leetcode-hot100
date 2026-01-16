#include <stdio.h>
#include <stdbool.h>
#include <uthash/uthash.h>

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

struct hashtable {
	struct ListNode *key;
	UT_hash_handle hh;
};

bool main(struct ListNode *head) {
#if 0 
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
			return true;
	}
#else
/* 哈希表 */
	struct hashtable *table = NULL;

	while (head != NULL) {
		struct hashtable *tmp;

		HASH_FIND_PTR(table, &head, tmp);

		if (tmp != NULL) {
			return true;
		}

		tmp = (struct hashtable*)malloc(sizeof(struct hashtable));
		tmp->key = head;
		HASH_ADD_PTR(table, key, tmp);

		head = head->next;
	}

	return false;

#endif
}