#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char s[120];
} str;

int cmp(const void* a, const void* b)
{
    double d1 = atof((*(str*)a).s), d2 = atof((*(str*)b).s);
    if (fabs(d1 - d2) >= 1e-6) {
        if (d1 > d2) return 1;
        else return -1;
    }
    else return 0;
}

int main()
{
    str strs[120];
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", strs[i].s);
    }
    qsort(strs, n, sizeof(str), cmp);
    for (int i = 0; i < n; i++) {
        printf("%s\n", strs[i].s);
    }
    return 0;
}