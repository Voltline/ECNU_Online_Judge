#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 1000009

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int gcd(int a, int b)
{
    if (a % b == 0) return b;
    else return gcd(b, a%b);
}

int valley[1020] = {0};

void solve(int n, int s)
{
    valley[n] = INF;
    int ans_int = 0, ans_fz = 0, ans_fm = 0;
    for (int i = 1; i <= n; i++) {
        int c = (valley[i] - valley[i-1]) * i;
        if (s < c) {
            ans_int = valley[i-1] + s/i;
            ans_fz = s % i;
            ans_fm = i;
            break;
        }
        else {
            s -= c;
        }
    }
    int g = gcd(ans_fz, ans_fm);
    ans_fz /= g;
    ans_fm /= g;
    if (ans_int != 0) {
        printf("%d", ans_int);
        if (ans_fz != 0) {
            printf("+%d/%d\n", ans_fz, ans_fm);
        }
    }
    else {
        if (ans_fz != 0) {
            printf("%d/%d\n", ans_fz, ans_fm);
        }
        else printf("0\n");
    }
}

int main()
{
    int n = 0, s = 0;
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &valley[i]);
    }
    qsort(valley, n, sizeof(int), cmp);
    solve(n, s);
    return 0;
}
