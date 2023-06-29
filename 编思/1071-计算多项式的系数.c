#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int mod = 10007;

int dp[1005][1005] = {{1}, {1, 1}};

void DP()
{
    for (int i = 2; i <= 1000; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
            }
        }
    }
    /*
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }*/
}

int main()
{
    DP();
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int a = 0, b = 0, k = 0, n = 0, m = 0;
        scanf("%d%d%d%d%d", &a, &b, &k, &n, &m);
        long long c = 1, d = 1;
        for (int i = 0; i < n; i++) {
            c = ((c % mod) * (a % mod)) % mod;
        }
        for (int i = 0; i < m; i++) {
            d = ((d % mod) * (b % mod)) % mod;
        }
        long long e = ((c % mod)*(d % mod)) % mod;
        printf("case #%d:\n%lld\n", i, ((e % mod) * (dp[k][n] % mod) % mod));
    }
    return 0;
}
