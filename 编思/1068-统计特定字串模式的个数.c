#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int int_pow(int m)
{
    int ans = 1;
    for (int i = 0; i < m; i++) {
        ans *= 2;
    }
    return ans;
}

int f(int n, int m)
{
    if (n < m) return 0;
    else if (n == m) return 1;
    else return 2*f(n-1, m) - f(n-1-m, m) + int_pow(n-m-1);
}

int main()
{
    int n = 0, m = 0;
    while (n != -1 && m != -1) {
        scanf("%d%d", &n, &m);
        if (n != -1 && m != -1) {
            printf("%d\n", f(n, m));
        }
    }
    return 0;
}
