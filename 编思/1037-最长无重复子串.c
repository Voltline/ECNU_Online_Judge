#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000020

int main()
{
    char* s = (char*)malloc(MAX * sizeof(char));
    scanf("%s", s);
    char* p = s;
    int max_len = -1;
    int start = 0;
    int str_length = strlen(s);
    for (int i = 0; i < str_length; i++) {
        int alpha[128] = {0}, now_len = 0;
        for (int t = i; (alpha[s[t]] == 0) && (t < str_length); t++) {
            alpha[s[t]] = 1;
            now_len++;
        }
       if (now_len > max_len) {
            start = i;
            max_len = now_len;
       }
    }

    for (int i = start; i < start + max_len; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
    free(s);
    return 0;
}
