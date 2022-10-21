#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char ID[12];
	int score;
} record;

int compare(const void* e1, const void* e2);

int main()
{
	int n = 0, score = 0; 
	char ID[12];
	record records[100] = {{0, 0}}, temp = {0, 0};
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", ID, &score);
		strcpy(temp.ID, ID);
		temp.score = score;
		records[i] = temp;
	}
	qsort(records, n, sizeof(record), compare);
	for (int i = 0; i < n; i++) {
		if (records[i].score < 60) {
			break;
		}
		else {
			printf("%s %d\n", records[i].ID, records[i].score);
		}
	}
	return 0;
}

int compare(const void* e1, const void* e2)
{
	if ((int)(((record*)e2)->score - ((record*)e1)->score) != 0) {
		return (int)(((record*)e2)->score - ((record*)e1)->score);
	}
	else {
		return strcmp(((record*)e1)->ID, ((record*)e2)->ID);
	}
}