#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

typedef struct 
{
	char c_upper;
	char c_lower;
	double frequency;	
} Alphabet;

Alphabet alphabet[30];

int compare(const void* c1, const void* c2);

int main()
{
	for (int i = 0; i < 26; i++) {
		alphabet[i] = (Alphabet){(char)('A'+i), (char)('a'+i), 0};
	}

	int T = 0;
	scanf("%d", &T);
	char line[120] = {0};
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 26; j++) {
			scanf("%lf", &(alphabet[j].frequency));
		}
		getchar();
		fgets(line, 120, stdin);
		line[strlen(line) - 1] = 0;
		qsort(line, strlen(line), sizeof(char), compare);
		printf("case #%d:\n%s\n", i, line);
	}
	return 0;
}

int compare(const void* c1, const void* c2)
{
	char c1_inner = tolower(*(char*)c1), c2_inner = tolower(*(char*)c2);
	
	if (c1_inner != c2_inner) {
		if (fabs(alphabet[c1_inner-97].frequency - alphabet[c2_inner-97].frequency) > 1e-5) {
			if (alphabet[c1_inner-97].frequency > alphabet[c2_inner-97].frequency) return -1;
			else return 1;
		}
		else {
			return c1_inner - c2_inner;
		} 
	}
	else {
		return *(char*)c2 - *(char*)c1;
	}
}