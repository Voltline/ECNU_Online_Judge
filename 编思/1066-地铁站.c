#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve(int a, int n, int m, int x)
{
    if (x == 1 || x == 2) printf("%d\n", a);
    else {
        long long dp[21] = {0, a, a, 2*a};
        dp[n] = 0;
        long long up[21] = {a, 0, a};
        long long k_coef[21] = {0, 0, 0, 0, 1},
        a_coef[21] = {0, 1, 0, 1, 0};
        for (int i = 5; i < 21; i++) {
            k_coef[i] = k_coef[i-1] + k_coef[i-2];
            a_coef[i] = a_coef[i-1] + a_coef[i-2];
        }
        long long a_all = 0, k_all = 0;
        for (int i = 1; i <= n-1; i++) {
            a_all += a_coef[i];
            k_all += k_coef[i];
        }
        long long k = (m - a_all * a)/k_all;
        a_all = 0;
        k_all = 0;
        for (int i = 1; i <= x; i++) {
            a_all += a_coef[i];
            k_all += k_coef[i];
        }
        printf("%lld\n", a_all * a + k_all * k);
    }
}

int main()
{
    int a = 0, n = 0, m = 0, x = 0;
    scanf("%d%d%d%d", &a, &n, &m, &x);
    solve(a, n, m, x);
    return 0;
}
