#include <stdio.h>
#include <string.h>

int main()
{
	char s[60] = {0};
	scanf("%s", s);
	int cur_length = 1, max_length = -1;
	for (int i = 0; i < strlen(s) - 1; i++) {
		if (s[i+1] != s[i]) cur_length++;
		else {
			max_length = (cur_length > max_length) ? cur_length : max_length;
			cur_length = 1;
		}
	}
	max_length = (cur_length > max_length) ? cur_length : max_length;
	printf("%d\n", max_length);
	return 0;
}