#include <stdio.h>
#include <stdlib.h>
#define MAX 10001
long long arr[MAX];
int cmp(const void* a, const void* b);
int cnt_digit(long long a);

int main()
{
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n = 0;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%lld", &arr[j]);
		}
		qsort(arr, n, sizeof(long long), cmp);
		printf("case #%d:\n", i);
		for (int j = 0; j < n; j++) {
			printf("%lld ", arr[j]);
		}
		printf("\n");
	}
	return 0;
}

int cmp(const void* a, const void* b)
{
	long long a_1 = *(long long*)a, b_1 = *(long long*)b;
	int size_a = cnt_digit(a_1), size_b = cnt_digit(b_1);
	if (size_a != size_b) {
		return size_b - size_a;
	}
	else {
		if (a_1 > b_1) return 1;
		else if (a_1 == b_1) return 0;
		else return -1;
	}
}

int cnt_digit(long long a)
{
	unsigned long long b = (unsigned long long)a;
	int cnt = 0;
	while (b > 0) {
		cnt += b & 1;
		b >>= 1;
	}
	return cnt;
}