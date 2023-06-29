#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f(int n, int p, int m, int t)
{
    if (m == 0 && p != t) return 0;
    else if (m == 0 && p == t) return 1;
    else if (m > 0) {
        if (t == 1) return f(n, p, m-1, t+1);
        if (t == n) return f(n, p, m-1, t-1);
        return f(n, p, m-1, t-1) + f(n, p, m-1, t+1);
    }
}

int main()
{
    int cas = 0;
    scanf("%d", &cas);
    for (int i = 0; i < cas; i++) {
        int n = 0, p = 0, m = 0, t = 0;
        scanf("%d%d%d%d", &n, &p, &m, &t);
        if (t > n) printf("0\n");
        else printf("%d\n", f(n, p, m, t));
    }
    return 0;
}
