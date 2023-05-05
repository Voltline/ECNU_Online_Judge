#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
	char* s;
} String;

int hasDigit(String s)
{
	char* str = s.s;
	for (int i = 0; i < strlen(str); i++) {
		if (isdigit(str[i])) return 1;
	}
	return 0;
}

int toDigit(char c)
{
	return c - '0';
}

int compare_digit(String s1, String s2)
{
	int low1 = 0, low2 = 0;
	for (int i = 0; i < strlen(s1.s); i++) {
		if (isdigit(s1.s[i])) {
			low1 = i;
			break;
		}
	}
	for (int i = 0; i < strlen(s2.s); i++) {
		if (isdigit(s2.s[i])) {
			low2 = i;
			break;
		}
	}
	int s1_num = atoi(s1.s + low1);
	int s2_num = atoi(s2.s + low2);
	return s1_num - s2_num;
}

int strnumcmp(String s1, String s2)
{
	if (!hasDigit(s1) && !hasDigit(s2)) return strcmp(s1.s, s2.s);
	else {
		if (!hasDigit(s1)) return -1;
		else if (!hasDigit(s2)) return 1;
		else {
            if (compare_digit(s1, s2) != 0) return compare_digit(s1, s2);
            else return strcmp(s1.s, s2.s);
		}
	}
}

int cmp(const void* a, const void* b)
{
	return strnumcmp(*(String*)a, *(String*)b);
}

int main()
{
	String* strs = (String*)malloc(100 * sizeof(String));
	for (int i = 0; i < 100; i++) {
		strs[i].s = (char*)malloc(32 * sizeof(char));
	}
	int j = 0;
	char* temp = (char*)malloc(40 * sizeof(char));
	while (scanf("%s", temp) != EOF) {
		strcpy(strs[j].s, temp);
		j++;
	}

	qsort(strs, j, sizeof(String), cmp);
	for (int u = 0; u < j; u++) {
		printf("%s ", strs[u].s);
	}
	for (int v = 0; v < 100; v++) {
		free(strs[v].s);
	}
	free(strs);
	return 0;
}
