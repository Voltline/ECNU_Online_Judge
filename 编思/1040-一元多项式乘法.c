#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isDigit(char c)
{
    if (c >= '0' && c <= '9') return 1;
    else return 0;
}

void transform(char* str, int d[]) // return the highest item
{
    char* s = str;
    int sign = 1, coef = 0, dim = 0;
    while (*s) {
        if (*s == '-') sign = -1, s++;
        else if (*s == '+') s++;
        while (isDigit(*s)) {
            coef = 10 * coef + (*s++ - '0');
        }
        if (coef == 0) coef = 1;
        if (*s != 'x') {
            d[0] = coef * sign;
            coef = 0;
            sign = 1;
            return;
        }
        else s++;
        if (*s == '^') s++;
        while (isDigit(*s)) dim = 10 * dim + (*s++ - '0');
        if (dim == 0) dim = 1;
        d[dim] = coef * sign;
        dim = 0;
        coef = 0;
        sign = 1;
    }
}

void multiply(int d1[], int d2[])
{
    int ans[200] = {0};
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            ans[i+j] += d1[i] * d2[j];
        }
    }
    for (int i = 99; i >= 0; i--) {
        if (ans[i] != 0) printf("%d ", ans[i]);
    }
    printf("\n");
}

void solve()
{
    char in[120] = {0};
    char poly1[120] = {0}, poly2[120] = {0};
    int cnt = 0;
    while (scanf("%s%s", poly1, poly2) == 2) {
        int d1[120] = {0}, d2[120] = {0};
        transform(poly1, d1);
        transform(poly2, d2);
        multiply(d1, d2);
    }
}

int main()
{
    solve();
    return 0;
}
