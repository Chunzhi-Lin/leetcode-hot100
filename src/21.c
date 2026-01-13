#include <stdio.h>
#include <stdlib.h>

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

// 创建节点
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
#if 0
	/* 递归 */
	if (list1 == NULL) {
		return list2;
	} else if (list2 == NULL) {
		return list1;
	} else if (list1->val > list2->val) {
		list2->next = mergeTwoLists(list1, list2->next);
		return list2;
	} else {
		list1->next = mergeTwoLists(list1->next, list2);
		return list1;
	}
#else
	if (list1 == NULL) {
		return list2;
	} else if (list2 == NULL)
		return list1;

	struct ListNode *head;

	head = createNode(-1);

	struct ListNode *prehead = head;
	while (list1 != NULL && list2 != NULL) {
		if (list1->val < list2->val) {
			prehead->next = list1;
			list1 = list1->next;
		} else {
			prehead->next = list2;
			list2 = list2->next;
		}
		prehead = prehead->next;
	}

	prehead->next = list1 == NULL ? list2 : list1;

	return head->next;
#endif
}

// 打印链表
void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d", curr->val);
        if (curr->next != NULL) printf(" -> ");
        curr = curr->next;
    }
    printf("\n");
}

// 释放链表
void freeList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    // 测试用例
    printf("=== 测试合并两个有序链表 ===\n");
    
    // 创建链表1: 1 -> 3 -> 5
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);
    
    // 创建链表2: 2 -> 4 -> 6
    struct ListNode* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);
    
    printf("链表1: ");
    printList(list1);
    printf("链表2: ");
    printList(list2);
    
    struct ListNode* merged = mergeTwoLists(list1, list2);
    printf("合并后: ");
    printList(merged);
    
    // 释放内存
    freeList(merged);
    
    return 0;
}