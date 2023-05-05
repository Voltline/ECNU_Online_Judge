#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long ull;

ull arr[1001] = {0}, ne[500501] = {0};

int cmp(const void* a, const void* b)
{
    ull a1 = *(ull*)a, b1 = *(ull*)b;
    if (a1 > b1) return 1;
    else if (a1 == b1) return 0;
    else return -1;
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n = 0, m = 0;
        scanf("%d%d", &n, &m);
        ull cumsum = 0, in = 0;
        for (int j = 0; j < n; j++) {
            scanf("%llu", &in);
            cumsum += in;
            arr[j] = cumsum;
        }
        int cnt = 1;
        for (; cnt <= n; cnt++) ne[cnt] = arr[cnt-1];
        for (int j = 0; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                ne[cnt++] = arr[k] - arr[j];
            }
        }
        qsort(ne+1, n*(n+1)/2, sizeof(ull), cmp);
        for (int j = 0; j < n*(n+1)/2; j++) {
            ne[j+1] += ne[j];
        }
        int L = 0, U = 0;
        printf("case #%d:\n", i);
        for (int j = 0; j < m; j++) {
            scanf("%d%d", &L, &U);
            printf("%llu\n", ne[U] - ne[L-1]);
        }
    }
    return 0;
}
