#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char mails[2000000] = {0};

typedef struct {
	char* name;
	char* host;
} email;

email emails[400000];

int find_at(char* amail) 
{
	for (int i = 0; i < strlen(amail); i++) {
		if (amail[i] == '@') {
			amail[i] = '\0';
			return i;
		}
	}
}

int cmp(const void* a, const void* b)
{
	email e1 = *(email*)a, e2 = *(email*)b;
	if (strcmp(e1.host, e2.host) != 0) {
		return strcmp(e1.host, e2.host);
	}
	else {
		return strcmp(e2.name, e1.name);
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	char* s = mails;
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		int org = strlen(s);
		int pos = find_at(s);
		emails[i].name = s;
		emails[i].host = s+pos+1;
		s += org+1;
	}
	qsort(emails, n, sizeof(email), cmp);
	for (int i = 0; i < n; i++) {
		printf("%s@%s\n", emails[i].name, emails[i].host);
	}
	return 0;
}