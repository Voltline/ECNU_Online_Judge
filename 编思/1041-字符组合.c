#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char c[20] = {0};

int Set(const char* str)
{
    memset(c, 0, 20 * sizeof(char));
    int cnt = 1, len = strlen(str);
    c[0] = str[0];
    for (int i = 1; i < len; i++) {
        if (c[cnt-1] != str[i]) c[cnt++] = str[i];
    }
    return cnt;
}

int cmp(const void* a, const void* b)
{
    return *(char*)a - *(char*)b;
}

void comb(char* s, char* char_comb)
{
    if (*s) {
        char left[20] = {0};
        sprintf(left, "%s%c", char_comb, s[0]);
        printf("%s\n", left);
        comb(s+1, left);
        comb(s+1, char_comb);
    }
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char str[20] = {0};
        scanf("%s", str);
        int len = strlen(str);
        qsort(str, len, sizeof(char), cmp);
        int size = Set(str);
        char comb_str[20] = {0};
        printf("case #%d:\n", i);
        comb(c, comb_str);
    }
    return 0;
}
