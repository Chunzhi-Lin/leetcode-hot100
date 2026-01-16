#include <stdio.h>
#include <uthash/uthash.h>

struct hashtable {
	int num;
	int idx;
	UT_hash_handle hh;
};

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	struct hashtable *table = NULL;
	struct hashtable *tmp;
	int i, val;

	for (i = 0; i < numsSize; i++) {
		val = target - nums[i];
		HASH_FIND_INT(table, &val, tmp);

		if (tmp != NULL) {
			int *ans = malloc(2 * sizeof(int));
			*returnSize = 2;
			ans[0] = tmp->idx;
			ans[1] = i;
			return ans;
		}

		tmp = (struct hashtable*)malloc(sizeof(struct hashtable));
		tmp->num = nums[i];
		tmp->idx = i;
		HASH_ADD_INT(table, num, tmp);
	}

	*returnSize = 0;
	return NULL;
}