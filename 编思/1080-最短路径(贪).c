#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2147483647

int dir[][2] ={ {1, 0}, {0, 1} };

int check_dir(char c, int m, int n, int x, int y)
{
    switch (c) {
    case 'R':
        y++;
        break;
    case 'D':
        x++;
        break;
    }
    if (x < m && y < n) return 1;
    else return 0;
}

int main()
{
	char str[400] = {0};
	int ptr = 0;
    int n = 0, m = 0;
    scanf("%d%d", &m, &n);
    int** mat = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    int x = 0, y = 0;
    int sum = mat[0][0];
    int check_RD[2] = {1, 1};
    for (int i = 0; i < n+m-2; i++) {
        check_RD[0] = check_dir('R', m, n, x, y);
        check_RD[1] = check_dir('D', m, n, x, y);
        int R = MAX, D = MAX;
        if (check_RD[0]) R = mat[x][y+1];
        if (check_RD[1]) D = mat[x+1][y];
        if (R > D) {
            x++;
            sum += D;
            str[ptr++] = 'D';
        }
        else {
            y++;
            sum += R;
            str[ptr++] = 'R';
        }
    }
    printf("%d\n", sum);
    printf("%s\n", str);

    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}
