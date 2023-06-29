#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int presum[201][201] = {{0}};

void solve(int n, int m, int k)
{
    int len = (n > m) ? m : n;
    int ans = 0;
    for (int L = 2; L <= len; L++) {
        for (int i = 1; i <= n-L+1; i++) { // left upper
            for (int j = 1; j <= m-L+1; j++) {
                int sum = 0, t = L - 1;
                for (int r = i; r <= i+L-1; r++) {
                    sum += presum[r][j+t] - presum[r][j-1];
                    t--;
                }
                if (sum >= k) ans++;
            }
        }

        for (int i = n; i >= L; i--) { // left lower
            for (int j = 1; j <= m-L+1; j++) {
                int sum = 0, t = L - 1;
                for (int r = i; r >= i-L+1; r--) {
                    sum += presum[r][j+t] - presum[r][j-1];
                    t--;
                }
                if (sum >= k) ans++;
            }
        }

        for (int i = 1; i <= n-L+1; i++) { // right upper
            for (int j = m; j >= L; j--) {
                int sum = 0, t = L - 1;
                for (int r = i; r <= i+L-1; r++) {
                    sum += presum[r][j] - presum[r][j-t-1];
                    t--;
                }
                if (sum >= k) ans++;
            }
        }

        for (int i = n; i >= L; i--) { // right lower
            for (int j = m; j >= L; j--) {
                int sum = 0, t = L - 1;
                for (int r = i; r >= i-L+1; r--) {
                    sum += presum[r][j] - presum[r][j-t-1];
                    t--;
                }
                if (sum >= k) ans++;
            }
        }

    }
    printf("%d\n", ans);
}

int main()
{
    int n = 0, m = 0, k = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int temp = 0;
            scanf("%d", &temp);
            presum[i][j] = presum[i][j-1] + temp;
        }
    }
    solve(n, m, k);
    return 0;
}
