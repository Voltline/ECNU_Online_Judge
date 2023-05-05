#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char c[3] = {'A', 'B', 'C'};

int check(const char* s, int len)
{
    for (int i = 0; i < len-1; i++) {
        if (s[i+1] == s[i]) return 1; // 1 for check false
    }
    return 0;
}

int clear(const char* s)
{
    int len_origin = strlen(s), len = len_origin;
    char s1[120] = {0};
    strcpy(s1, s);
    while (check(s1, len)) {
        for (int i = 0; i < len-1; i++) {
            if (s1[i+1] == s1[i]) {
            	int j = i+1;
                for (; j < len && s1[j] == s1[i]; j++);
                memmove(&s1[i], &s1[j], (len - j) * sizeof(char));
                len -= (j-i);
                i--;
                s1[len] = 0;
            }
        }
    }
    return len_origin - len;
}

int process(const char* s)
{
    int len = strlen(s), max = -1;
    char s1[120] = {0};
    strcpy(s1, s);
	for (int i = 0; i < len; i++) {
        memmove(&s1[i+1], &s[i], (len-i) * sizeof(char));
        for (int j = 0; j < 3; j++) {
            s1[i] = c[j];
            int temp = clear(s1);
            max = (temp > max) ? temp : max;
		}
		memset(s1, 0, 120 * sizeof(char));
       	strcpy(s1, s);
    }
    return max;
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    char s[120] = {0};
    for (int i = 0; i < T; i++) {
        scanf("%s", s);
        int max = process(s);
        printf("case #%d:\n%d\n", i, max);
    }
    return 0;
}
