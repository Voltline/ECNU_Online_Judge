#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 120000
#define abs(a) ((a) >= 0) ? (a) : -(a)
typedef struct
{
    char c;
    int cnt;
} PAIR;

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int stat(char* str, PAIR* p)
{
    int size = 0, cnt = 1;
    char prev = 0; // TODO Down
    for (prev = *str; *str; cnt++, prev = *str++) {
        if (prev != *str) {
            p[size].c = prev;
            p[size++].cnt = cnt;
            cnt = 0;
        }
    }
    p[size].c = prev;
    p[size++].cnt = cnt;
    return size;
}

int check(PAIR (*f)[100], int n, int* fn)
{
    for (int i = 0; i < n; i++) if (fn[i] != fn[0]) return 0;
    for (int i = 0; i < fn[0]; i++) {
        for (int j = 1; j < n; j++) {
            if (f[j][i].c != f[0][i].c) return 0;
        }
    }
    return 1;
}

void solve()
{
    int sizes[N] = {0};
    PAIR pairs[N][100];
    char s[120] = {0};
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        sizes[i] = stat(s, pairs[i]);
    }
    int ans = 0;
    int a[N] = {0};
    int c = check(pairs, n, sizes);
    if (c) {
        for (int i = 0; i < sizes[0]; i++) {
            for (int j = 0; j < n; j++) {
                a[j] = pairs[j][i].cnt;
            }
            qsort(a, n, sizeof(int), cmp);
            for (int j = 0; j < n; j++) ans += abs(a[j] - a[n/2]);
        }
        printf("%d\n", ans);
    }
    else printf("-1\n");
}

int main()
{
    solve();
    return 0;
}
