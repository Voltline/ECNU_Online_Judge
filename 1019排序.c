#include <stdio.h>
#include <stdlib.h>
int compare(const void* e1, const void* e2);
int main()
{
	int T = 0, N = 0;
	scanf("%d", &T);
	int cnt = 0, cnts[100] = { 0 };
	int nums[10][100], temp[100] = { 0 };
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &(temp[j]));
		}
		qsort(temp, N, sizeof(int), compare);
		int zeros = 0, temp_cnt = N;
		for (int j = 0; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (temp[j] != temp[k]) {
					break;
				}
				else {
					temp[k] = 0;
					zeros++;
					temp_cnt--;
				}
			}
			j += zeros;
			zeros = 0;
		}
		cnts[i] = temp_cnt;
		int u = 0;
		for (int j = 0; j < N; j++) {
			if (temp[j] != 0) {
				nums[i][u++] = temp[j];
				temp[j] = 0;
			}
		}
	}
	for (int i = 0; i < T; i++) {
		printf("case #%d:\n", i);
		int j = 0;
		for (j = 0; j < cnts[i] - 1; j++) {
			printf("%d ", nums[i][j]);
		}
		printf("%d\n", nums[i][j]);
	}
	return 0;
}
int compare(const void* e1, const void* e2)
{
	if ((*(int*)e1) % 10 - (*(int*)e2) % 10 != 0) {
		return (*(int*)e1) % 10 - (*(int*)e2) % 10;
	}
	else {
		return *(int*)e1 - *(int*)e2;
	}
}