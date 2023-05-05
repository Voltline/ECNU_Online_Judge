#include <stdio.h>
#include <stdlib.h>

int score_M[10] = {0};

typedef struct {
	char ID[12];
	int score;
} student;

student arr[500];

int cmp(const void* a, const void* b)
{
	student s1 = *(student*)a, s2 = *(student*)b;
	if (s1.score != s2.score) {
		return s2.score - s1.score;
	}	
	else {
		long long id_1 = atoll(s1.ID), id_2 = atoll(s2.ID);
		if (id_1 > id_2) return 1;
		else if (id_1 == id_2) return 0;
		else return -1;
	}
}

int main()
{
	int T = 0, N = 0, M = 0, G = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%d%d", &N, &M, &G);
		for (int j = 0; j < M; j++) {
			scanf("%d", &score_M[j]);
		}
		int u = 0, temp_score = 0, temp_total = 0;
		for (int j = 0; j < N; j++) {
			scanf("%s%d", arr[j].ID, &u);
			for (int k = 0; k < u; k++) {
				scanf("%d", &temp_score);
				temp_total += score_M[temp_score-1];
			}
			arr[j].score = temp_total;
			temp_total = 0;
		}
		qsort(arr, N, sizeof(student), cmp);
		printf("case #%d:\n", i);
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (arr[j].score >= G) cnt++;
			else break;
		}
		printf("%d\n", cnt);
		for (int j = 0; j < cnt; j++) {
			printf("%s %d\n", arr[j].ID, arr[j].score);
		}
	}
	return 0;
}