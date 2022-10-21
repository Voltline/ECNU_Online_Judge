#include <stdio.h>
#include <stdlib.h>

int compare(const void* e1, const void* e2);

typedef struct {
	int ID;
	char name[1024];
	int a_score;
	int b_score;
	int c_score;
} student;

int main()
{
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n = 0;
		int ID, a_score, b_score, c_score;
		char name[1024];
		scanf("%d", &n);
		student* students = (student*)malloc(n*sizeof(student));
		for (int j = 0; j < n; j++) {
			scanf("%d%s%d%d%d", &ID, name, &a_score, &b_score, &c_score);
			student temp = {ID, name, a_score, b_score, c_score};
			students[j] = temp;
		}
		qsort(students, n, sizeof(student), compare);
		printf("case #%d:\n", i);
		for (int j = 0; j < n; j++) {
			printf("%d %s %d %d %d\n", students[i].ID, students[i].name,
			 students[i].a_score, students[i].b_score, students[i].c_score);
		}
		free(students);
	}
	return 0;
}

int compare(const void* e1, const void* e2)
{
	student *s1 = (student*)e1, *s2 = (student*)e2;
	int sum_s1 = s1->a_score + s1->b_score + s1->c_score;
	int sum_s2 = s2->a_score + s2->b_score + s2->c_score;
	if (sum_s1 != sum_s2) {
		return sum_s1 - sum_s2;
	}
	else {
		return s1->ID - s2->ID;
	}
}