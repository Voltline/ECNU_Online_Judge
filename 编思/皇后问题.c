#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int map[220][220] = {{0}};
    int qx = 0, qy = 0;
    getchar();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c = getchar();
            if (c == 'E') map[i][j] = 0;
            else if (c == 'Q') map[i][j] = 30000;
            else if (c == 'q') {
                map[i][j] = 20000;
                qx = i;
                qy = j;
            }
        }
        getchar();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] >= 30000) {
                for (int k = 0; k < n; k++) {
                    if (k != j) map[i][k] += 1;
                    if (k != i) map[k][j] += 1;
                }
                int x = i, y = j;
                while (x >= 0 && x < n && y >= 0 && y < n) {
                    if (x != i && y != j) map[x][y] += 1;
                    x++;
                    y++;
                }
                x = i, y = j;
                while (x >= 0 && x < n && y >= 0 && y < n) {
                    if (x != i && y != j) map[x][y] += 1;
                    x--;
                    y--;
                }
                x = i, y = j;
                while (x >= 0 && x < n && y >= 0 && y < n) {
                    if (x != i && y != j) map[x][y] += 1;
                    x++;
                    y--;
                }
                x = i, y = j;
                while (x >= 0 && x < n && y >= 0 && y < n) {
                    if (x != i && y != j) map[x][y] += 1;
                    x--;
                    y++;
                }
            }
        }
    }
    int x = qx, y = qy;
    long long ans = 0;
    for (int k = 0; k < n; k++) {
        if (k != y && (map[x][k] == 0 || map[x][k] == 30000)) ans++;
        if (k != x && (map[k][y] == 0 || map[k][y] == 30000)) ans++;
    }
    x = qx, y = qy;
    while (x >= 0 && x < n && y >= 0 && y < n) {
        if (map[x][y] == 0 || map[x][y] == 30000) ans++;
        x++;
        y++;
    }
    x = qx, y = qy;
    while (x >= 0 && x < n && y >= 0 && y < n) {
        if (x != qx && y != qy && map[x][y] == 0 || map[x][y] == 30000) ans++;
        x--;
        y--;
    }
    x = qx, y = qy;
    while (x >= 0 && x < n && y >= 0 && y < n) {
        if (x != qx && y != qy && map[x][y] == 0 || map[x][y] == 30000) ans++;
        x++;
        y--;
    }
    x = qx, y = qy;
    while (x >= 0 && x < n && y >= 0 && y < n) {
        if (x != qx && y != qy && map[x][y] == 0 || map[x][y] == 30000) ans++;
        x--;
        y++;
    }
    printf("%lld\n", ans);
    return 0;
}
