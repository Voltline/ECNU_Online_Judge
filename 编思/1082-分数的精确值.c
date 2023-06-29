#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int status[100] = {0}, q[100] = {0};

void solve(int n, int m)
{
    printf("0.");
    int r = 1;
    int flag = 0;
    for (int i = 1; !flag; i++) {
        if (n == 0) {
            for (int j = 1; j < i; j++) printf("%d", q[j]);
            printf("\n");
            flag = 1;
        }
        else {
            if (!status[n]) {
                status[n] = i;
                q[i] = n*10/m;
                n = n * 10 % m;
            }
            else {
                for (int j = 1; j < i; j++) printf("%d", q[j]);
                printf("\n");
                printf("%d-%d\n", status[n], i-1);
                flag = 1;
            }
        }
    }
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        memset(status, 0, 100 * sizeof(int));
        memset(q, 0, 100 * sizeof(int));
        int n = 0, m = 0;
        scanf("%d%d", &n, &m);
        printf("case #%d:\n", i);
        solve(n, m);
    }
    return 0;
}
