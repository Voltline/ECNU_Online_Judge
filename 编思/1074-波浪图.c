#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char c;
    int line;
    int col;
} wave;

int cmp(const void* a, const void* b)
{
    wave w1 = *(wave*)a, w2 = *(wave*)b;
    if (w1.line != w2.line) {
        return w2.line - w1.line; // line is reversed
    }
    else {
        return w1.col - w2.col;
    }
}

int print(wave waves[], int n)
{
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0 && waves[i-1].line != waves[i].line) {
            cur = 0;
            printf("\n");
        }
        if (waves[i].col > cur) {
            for (; cur < waves[i].col; cur++) {
                putchar(' ');
            }
        }
        printf("%c", waves[i].c);
        cur++;
    }
    printf("\n");
}

int main()
{
    char line[100] = {0};
    while (scanf("%s", line) != EOF) {
        int len = strlen(line);
        int col = 0;
        wave waves[100];
        waves[0].c = line[0];
        waves[0].line = 0;
        waves[0].col = col++;
        for (int i = 1; i < len; i++) {
            waves[i].c = line[i];
            if (line[i] > line[i-1]) waves[i].line = waves[i-1].line + 1;
            else if (line[i] < line[i-1]) waves[i].line = waves[i-1].line - 1;
            else  waves[i].line = waves[i-1].line;
            waves[i].col = i;
        }
        qsort(waves, len, sizeof(wave), cmp);
        print(waves, len);
    }
    return 0;
}
