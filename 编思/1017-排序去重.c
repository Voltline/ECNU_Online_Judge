#include <stdio.h>
#include <stdlib.h>

int cmp_A(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int cmp_D(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;	
}

int main()
{
	char choice = 0;
	int arr[120] = {0}, n = 0;
	scanf("%c", &choice);
	while (scanf("%d", &arr[n++]) != EOF);
	if (choice == 'A') {
		qsort(arr, n-1, sizeof(int), cmp_A);
	}
	else {
		qsort(arr, n-1, sizeof(int), cmp_D);
	}
	int last = -1;
	for (int i = 0; i < n-1; i++) {
		if (last != arr[i]) {
			printf(" %d" + !i, arr[i]);
			last = arr[i];
		}
	}
	return 0;
}