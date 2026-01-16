#include <stdio.h>
#include <uthash/uthash.h>
#include <string.h>
#include <stdlib.h>

struct hashtable {
	char key[101];
	char **group;
	int size;
	UT_hash_handle hh;
};

int compare_char(const void *a, const void *b) {
	return *(char *)a - *(char *)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
	if (strsSize == 0) {
		*returnSize = 0;
		return NULL;
	}
	struct hashtable *table = NULL;
	char key[101];
	for (int i = 0; i < strsSize; i++) {
		strcpy(key, strs[i]);
		qsort(key, strlen(key), sizeof(char), compare_char);
		struct hashtable *tmp = NULL;
		HASH_FIND_STR(table, key, tmp);

		if (tmp == NULL) {
			tmp = malloc(sizeof(struct hashtable));
			tmp->size = 0;
			strcpy(tmp->key, key);
			tmp->group = NULL;
			HASH_ADD_STR(table, key, tmp);
		}
		tmp->group = realloc(tmp->group, (tmp->size + 1) * sizeof(char*));
		tmp->group[tmp->size++] = strs[i];
	}

	*returnSize = HASH_COUNT(table);

	int idx = 0;
	char*** result = malloc(*returnSize * sizeof(char**));
	*returnColumnSizes = malloc(*returnSize * sizeof(int));
	struct hashtable *curr, *prev;

	HASH_ITER(hh, table, curr, prev) {
		result[idx] = malloc(curr->size * sizeof(char*));
		(*returnColumnSizes)[idx] = curr->size;
		for (int i = 0; i < curr->size; i++) {
			result[idx][i] = curr->group[i];
		}

		idx++;

		free(curr->group);
		HASH_DEL(table, curr);
		free(curr);
	}

	return result;
}

int main() {
	char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	int strsSize = 6;
	int returnSize;
	int* returnColumnSizes;
	
	char*** result = groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);
	
	// 打印结果
	for (int i = 0; i < returnSize; i++) {
		printf("[");
		for (int j = 0; j < returnColumnSizes[i]; j++) {
			printf("\"%s\"", result[i][j]);
			if (j < returnColumnSizes[i] - 1) printf(",");
		}
		printf("]\n");
	}
	
	// 释放内存
	for (int i = 0; i < returnSize; i++) {
		free(result[i]);
	}
	free(result);
	free(returnColumnSizes);
	
	return 0;
}
