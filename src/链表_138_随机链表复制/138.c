#include <stdio.h>
#include <stdlib.h>

struct Node {
	int val;
	struct Node *next;
	struct Node *random;
};

struct Node* copyRandomList(struct Node* head) {
#if 0
/* 原地复制法 */
	if (head == NULL) return NULL;

	// 第一步：在每个原节点后面创建一个新节点
	struct Node* curr = head;
	while (curr != NULL) {
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->val = curr->val;
		newNode->next = curr->next;
		newNode->random = NULL;
		
		curr->next = newNode;
		curr = newNode->next;
	}

	// 第二步：设置新节点的random指针
	curr = head;
	while (curr != NULL) {
		if (curr->random != NULL) {
			curr->next->random = curr->random->next;
		}
		curr = curr->next->next;
	}

	// 第三步：分离两个链表
	struct Node* newHead = head->next;
	curr = head;
	while (curr != NULL) {
		struct Node* newNode = curr->next;
		curr->next = newNode->next;
		
		if (newNode->next != NULL) {
			newNode->next = newNode->next->next;
		}
		
		curr = curr->next;
	}

	return newHead;

#elif 1
/* 原地复制法 */
	if (head == NULL) return NULL;

	// 第一步：在每个原节点后面创建一个新节点
	struct Node* curr = head;
	while (curr != NULL) {
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->val = curr->val;
		newNode->next = curr->next;
		newNode->random = NULL;
		
		curr->next = newNode;
		curr = newNode->next;
	}

	// 第二步：设置新节点的random指针并分离链表
	curr = head;
	struct Node* newHead = head->next;
	while (curr != NULL) {
		struct Node* newNode = curr->next;

		if (curr->random != NULL) {
			newNode->random = curr->random->next;
		}
		curr = curr->next->next;
		if (newNode->next != NULL) {
			newNode->next = newNode->next->next;
		}
	}

	return newHead;
#else

#endif
}