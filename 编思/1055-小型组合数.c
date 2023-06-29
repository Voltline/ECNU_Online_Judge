#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long ll;

ll dp[41][41] = {{1}, {1, 1}};

void DP()
{
    for (int i = 1; i <= 40; i++) {
        for (int j = 0; j <= 40; j++) {
            if (j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
}

int main()
{
    DP();
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n = 0, m = 0;
        scanf("%d%d", &n, &m);
        printf("case #%d:\n%lld\n", i, dp[n][m]);
    }
    return 0;
}
