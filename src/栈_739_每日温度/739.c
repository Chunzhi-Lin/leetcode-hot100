#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 /* hard code */

#if 0
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
	int* answer = (int*)calloc(temperaturesSize, sizeof(int));

	int* next = (int*)malloc(102 * sizeof (int));
	for (int i = 0; i < 101; i++)
		next[i] = temperaturesSize;

	for (int i = temperaturesSize - 1; i >= 0; i--) {
		next[temperatures[i]] = i;

		int min = temperaturesSize;
		for (int j = temperatures[i] + 1; j < 101; j++) {
			if (next[j] < min)
				min = next[j];
		}

		if (min == temperaturesSize)
			answer[i] = 0;
		else
			answer[i] = min - i;
	}

	*returnSize = temperaturesSize;
	return answer;
}
#else
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
	int *answer = calloc(temperaturesSize, sizeof(int));
	int *stack = calloc(temperaturesSize, sizeof(int));
	int top = -1;

	for (int i = 0; i < temperaturesSize; i++) {
		while (top >= 0 && (temperatures[i] > temperatures[stack[top]])) {
			answer[stack[top]] = i - stack[top];
			top -= 1;
		}
		top += 1;
		stack[top] = i;
	}

	free(stack);

	*returnSize = temperaturesSize;

	return answer;
}
#endif

int main() {
    // 测试用例1
    int temperatures1[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int size1 = sizeof(temperatures1) / sizeof(temperatures1[0]);
    int returnSize1;

    int* result1 = dailyTemperatures(temperatures1, size1, &returnSize1);
    printf("Test 1:\n");
    printf("Input: [73,74,75,71,69,72,76,73]\n");
    printf("Output: [");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d", result1[i]);
        if (i < returnSize1 - 1) printf(",");
    }
    printf("]\n\n");
    free(result1);

    // 测试用例2
    int temperatures2[] = {30, 40, 50, 60};
    int size2 = sizeof(temperatures2) / sizeof(temperatures2[0]);
    int returnSize2;

    int* result2 = dailyTemperatures(temperatures2, size2, &returnSize2);
    printf("Test 2:\n");
    printf("Input: [30,40,50,60]\n");
    printf("Output: [");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d", result2[i]);
        if (i < returnSize2 - 1) printf(",");
    }
    printf("]\n\n");
    free(result2);

    // 测试用例3
    int temperatures3[] = {30, 60, 90};
    int size3 = sizeof(temperatures3) / sizeof(temperatures3[0]);
    int returnSize3;

    int* result3 = dailyTemperatures(temperatures3, size3, &returnSize3);
    printf("Test 3:\n");
    printf("Input: [30,60,90]\n");
    printf("Output: [");
    for (int i = 0; i < returnSize3; i++) {
        printf("%d", result3[i]);
        if (i < returnSize3 - 1) printf(",");
    }
    printf("]\n");
    free(result3);

    return 0;
}