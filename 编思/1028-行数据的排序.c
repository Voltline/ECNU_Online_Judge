#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int* line;
} Line;

Line arr[1000] = {NULL};

int cmp(const void* a, const void* b)
{
    Line pl1 = *(Line*)a, pl2 = *(Line*)b;
    int len1 = pl1.line[0], len2 = pl2.line[0];
    int min_len = (len1 < len2) ? len1 : len2;
    for (int i = 1; i <= min_len; i++) {
        if (pl1.line[i] != pl2.line[i]) return pl2.line[i] - pl1.line[i];
    }
    return pl2.line[0] - pl1.line[0];
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < 1000; i++) {
        arr[i].line = (int*)malloc(51 * sizeof(int));
    }
    for (int i = 0; i < T; i++) {
        int n = 0;
        scanf("%d", &n);
        int cnt = 0, in = 0;
        for (int j = 0; j < n; j++) {
            do {
                scanf("%d", &in);
                if (in != -1) {
                    cnt++;
                    ((arr[j]).line)[cnt] = in;
                }
            } while (in != -1);
            ((arr[j]).line)[0] = cnt+1;
            cnt = 0;
        }
        qsort(arr, n, sizeof(Line), cmp);
        for (int j = 0; j < n; j++) {
            for (int k = 1; k < ((arr[j]).line)[0]; k++) {
                printf("%d ", ((arr[j]).line)[k]);
            }
            printf("\n");
        }
    }

    for (int i = 0; i < 1000; i++) {
        free(arr[i].line);
    }
    return 0;
}
