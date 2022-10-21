#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int index;
	int height;
} member;

typedef struct {
	int m; // query times
	int result[50]; // query result
} query;

int compare(const void* e1, const void* e2);

int main()
{
	int t = 0, n = 0, m = 0, hei = 0;
	scanf("%d", &t);
	query* queries = (query*)malloc(t * sizeof(query));
	int indexs[50] = { 0 }, index_temp = 0;
	member members[50] = {{0, 0}}, temp = {0, 0};
	for (int j = 0; j < t; j++) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &hei);
			temp.index = i + 1;
			temp.height = hei;
			members[i] = temp;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &index_temp);
			indexs[i] = index_temp;
		}
		qsort(members, n, sizeof(member), compare);
		queries[j].m = m;
		for (int i = 0; i < m; i++) {
			queries[j].result[i] = members[indexs[i] - 1].index;
		}
		temp.height = 0;
		temp.index = 0;
		for (int i = 0; i < n; i++) {
			members[i] = temp;
		}
	}
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < queries[i].m - 1; j++) {
			printf("%d ", queries[i].result[j]);
		}
		printf("%d\n", queries[i].result[queries[i].m - 1]);
	}
	return 0;
}

int compare(const void* e1, const void* e2)
{
	return ((member*)e2)->height - ((member*)e1)->height;
}