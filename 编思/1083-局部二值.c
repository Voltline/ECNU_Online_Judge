#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int pic[120][120] = {0};
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int LBP(int x, int y)
{
    int sum = 2147483647;
    for (int start = 0; start < 8; start++) {
        int temp = 0;
        for (int i = 0; i < 8; i++) {
            if (pic[x+dx[(i + start) % 8]][y+dy[(i + start) % 8]] >= pic[x][y]) {
                temp <<= 1;
                temp++;
            }
            else {
                temp <<= 1;
            }
        }
        if (temp < sum) sum = temp;
    }

    return sum;
}

int main()
{
    int W = 0, H = 0;
    scanf("%d%d", &W, &H);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%d", &pic[i][j]);
        }
    }
    for (int i = 1; i < H-1; i++) {
        for (int j = 1; j < W-1; j++) {
            printf(" %d"+!(j-1), LBP(i, j));
        }
        printf("\n");
    }
    return 0;
}
