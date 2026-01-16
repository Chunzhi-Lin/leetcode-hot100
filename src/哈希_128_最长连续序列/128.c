#include <stdio.h>
#include <uthash/uthash.h>

int longestConsecutive(int* nums, int numsSize) {
	/* TBD */

	return 0;
}

int main() {
	int test_cases[][10] = {
		{1, 2, 3, 4, 5},		   // 5
		{5, 4, 3, 2, 1},		   // 5
		{1, 3, 5, 7, 9},		   // 1
		{10, 5, 12, 3, 55, 6, 81, 4, 11, 2}, // 6 (2,3,4,5,6,10,11,12)
		{-1, -2, -3, 0, 1},		// 5
		{1, 1, 1, 1, 1},		   // 1
		{100, 99, 98, 97, 96, 95}, // 6
	};
	
	int expected[] = {5, 5, 1, 6, 5, 1, 6};
	
	for (int i = 0; i < 7; i++) {
		int size = (i < 3) ? 5 : 10;
		int result = longestConsecutive(test_cases[i], size);
		printf("测试用例 %d: 预期 %d, 实际 %d %s\n", 
			   i+1, expected[i], result, 
			   result == expected[i] ? "✓" : "✗");
	}
	
	return 0;
}
