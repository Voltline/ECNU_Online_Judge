#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2147483647

int Min(int a, int b)
{
	return (a < b) ? a : b;
}

typedef struct
{
    int sum;
    char path[410];
} node;

node dp[210][210] = {{0, {0}}};

int main()
{
    int map[210][210] = {{0}};
    int m = 0, n = 0;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    dp[0][0].sum = map[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i != 0 || j != 0) {
                int left = (i == 0) ? MAX : dp[i-1][j].sum,
                    up = (j == 0) ? MAX : dp[i][j-1].sum;
                int c = (left < up) ? 0 : 1;
                dp[i][j].sum = Min(left, up) + map[i][j];
                if (c == 0) {
                    strcpy(dp[i][j].path, dp[i-1][j].path);
                    dp[i][j].path[strlen(dp[i][j].path)] = 'D';
                }
                else {
                    strcpy(dp[i][j].path, dp[i][j-1].path);
                    dp[i][j].path[strlen(dp[i][j].path)] = 'R';
                }
            }
        }
    }

    printf("%d\n%s\n", dp[m-1][n-1].sum, dp[m-1][n-1].path);
    return 0;
}
