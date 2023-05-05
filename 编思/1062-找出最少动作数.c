#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stack[101] = {0};
int operate[101] = {0};

int check(int Move[][101], int s, int n)
{
    for (int i = 0; i < n; i++) {
        if (Move[s][i] < operate[i]) return 0;
    }
    return 1;
}

int main()
{
    int n = 0, m = 0;
    int Move[101][101] = {{0}};
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &Move[i][j]);
        }
    }
    int moves = 0;
    for (int j = 0; j < n; j++) {
        int min = Move[0][j];
        for (int i = 0; i < m; i++) {
            if (Move[i][j] < min) min = Move[i][j];
        }
        stack[j] = min;
        moves += min;
    }
    memcpy(operate, stack, 101 * sizeof(int));
    for (int i = 0; i < m; i++) {
        int temp_moves = 0;
        for (int j = 0; j < n; j++) {
            if (Move[i][j] > operate[j]) {
                temp_moves += Move[i][j] - operate[j];
                operate[j] = Move[i][j];
            }
        }
        moves += temp_moves;
        if (i != m-1) {
	        if (check(Move, i+1, n)) {
	            memcpy(stack, operate, 101 * sizeof(int));
	        }
	        else {
	            moves += temp_moves;
	            memcpy(operate, stack, 101 * sizeof(int));
	        }
		}
		else {
		    for (int i = 0; i < n; i++) {
		        moves += operate[i];
		        operate[i] = 0;
		    }
		}
    }

    printf("%d\n", moves);
    return 0;
}
