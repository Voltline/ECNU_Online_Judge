#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
int Integer[500] = {0};

int compare(const void* e1, const void* e2);
int main()
{
	int T = 0, N = 0;
	scanf("%d", &T);
	int temp = 0;
	int ans[2000] = {0};
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &temp);
			ans[j] = temp;	
			Integer[temp]++;
		}
		qsort(ans, N, sizeof(int),compare);
		printf("case #%d:\n", i);
		for (int j = 0; j < N-1; j++) {
			printf("%d ", ans[j]);
		}
		printf("%d\n", ans[N-1]);
		memset(Integer, 0, 2000);
		memset(ans, 0, N);
	}
	return 0;
}

int compare(const void* e1, const void* e2)
{
	if (Integer[*(int*)e1] - Integer[*(int*)e2] != 0) {
		return Integer[*(int*)e2] - Integer[*(int*)e1];
	}
	else {
		return *(int*)e1 - *(int*)e2;
	}
}