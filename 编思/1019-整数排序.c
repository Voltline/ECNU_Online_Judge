#include <stdio.h>
#include <stdlib.h>
#define abs(x) ((x) >= 0 ? (x) : -(x))

int cnt_digit(int a)
{
	a = abs(a);
	int cnt = 0;
	while (a > 0) {
		cnt++;
		a /= 10;
	}
	return cnt;
}

int cmp(const void* a, const void* b)
{
	int a1 = *(int*)a, b1 = *(int*)b;
	if (cnt_digit(a1) != cnt_digit(b1)) {
		return cnt_digit(b1) - cnt_digit(a1);
	}
	else {
		if (a1 > b1) return 1;
		else if (a1 == b1) return 0;
		else return -1;
	}
}

int main()
{
	int* nums = (int*)malloc(1000010 * sizeof(int));
	int n = 0;
	while (scanf("%d", &nums[n++]) != EOF);
	qsort(nums, n-1, sizeof(int), cmp);
	for (int i = 0; i < n-1; i++) {
		printf("%d ", nums[i]);
	}
	free(nums);
	return 0;
}