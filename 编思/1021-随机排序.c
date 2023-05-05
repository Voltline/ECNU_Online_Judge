#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char input[30] = {0};
int Table[26] = {0};

typedef struct
{
    char str_p[25];
} str;

void toTable()
{
    memset(Table, 0, sizeof(int) * 26);
    for (int i = 0; i < 26; i++) {
        Table[input[i]-'A'] = i;
    }
}

int cmp(const void* a, const void* b)
{
    str s1 = *(str*)a, s2 = *(str*)b;
    int len = (strlen(s1.str_p) < strlen(s2.str_p)) ? strlen(s1.str_p) : strlen(s2.str_p);
    for (int i = 0; i < len; i++) {
        if (toupper(s1.str_p[i]) != toupper(s2.str_p[i])) {
            return Table[toupper(s1.str_p[i])-'A'] - Table[toupper(s2.str_p[i])-'A'];
        }
    }
    return strlen(s1.str_p) - strlen(s2.str_p);
}

int main()
{
    while (scanf("%s", input) != EOF) {
        getchar();
        str strs[120];
        toTable();
        int i = 0;
        char c = 0;
        while (c != '\n') {
            scanf("%s", strs[i].str_p);
            c = getchar();
            i++;
        }
        qsort(strs, i, sizeof(str), cmp);
        for (int j = 0; j < i; j++) {
            if (j != i-1) printf("%s ", strs[j].str_p);
            else printf("%s\n", strs[j].str_p);
        }
    }
    return 0;
}
