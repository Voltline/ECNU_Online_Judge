#include <stdio.h>
#include <stdlib.h>
int compare(const void* e1, const void* e2);
int main()
{
	int N = 0, nums[100000], num = 0, query_list[100];
	int K = 0, index = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		nums[i] = num;
	}
	qsort(nums, N, sizeof(int), compare);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &index);
		query_list[i] = nums[index - 1];
	}
	for (int i = 0; i < K; i++) {
		printf("%d\n", query_list[i]);
	}
	return 0;
}

int compare(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}