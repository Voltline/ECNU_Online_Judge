#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	unsigned long long ans = 0;
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), cmp);
	
	for (int i = 0; i < n-1; i += 2) {
		ans += arr[i+1] - arr[i];
	}
	printf("%llu\n", ans);
	free(arr);
	return 0;
}