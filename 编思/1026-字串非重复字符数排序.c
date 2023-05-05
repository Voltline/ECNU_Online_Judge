#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char str[30];
    int size;
} elem;

int cmp_str(const void* a, const void* b)
{
    char c1 = *(char*)a, c2 = *(char*)b;
    return c1 - c2;
}

int set_size(const char* s)
{
    char temp[30];
    strcpy(temp, s);
    qsort(temp, strlen(s), sizeof(char), cmp_str);
    char last = 0;
    int cnt = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (temp[i] != last) {
            last = temp[i];
            cnt++;
        }
    }
    return cnt;
}

int cmp(const void* a, const void* b)
{
    elem e1 = *(elem*)a, e2 = *(elem*)b;
    if (e1.size != e2.size) {
        return e2.size - e1.size;
    }
    else {
        return strcmp(e1.str, e2.str);
    }
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n = 0;
        scanf("%d", &n);
        elem* elems = (elem*)malloc(n * sizeof(elem));
        for (int j = 0; j < n; j++) {
            scanf("%s", elems[j].str);
            int size_of_temp = set_size(elems[j].str);
            elems[j].size = size_of_temp;
        }
        qsort(elems, n, sizeof(elem), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j < n; j++) {
            printf("%s\n", elems[j].str);
        }
        free(elems);
    }
    return 0;
}
