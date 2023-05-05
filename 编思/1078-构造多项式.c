#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Print_coef(int c)
{
    if (c > 0) {
        printf("+");
        if (c != 1) printf("%d", c);
    }
    else {
        if (c != -1) printf("%d", c);
        else printf("-");
    }
}

void Print(int coef[])
{
    int first = 8;
    for (int i = 0; i < 9; i++) {
        if (coef[i] != 0) {
            first = i;
            break;
        }
    }
    for (int i = first; i < 9; i++) {
        if (i != 8 && coef[i] != 0) {
            if (i == first) {
                if (coef[i] > 0) {
                    if (coef[i] != 1) printf("%d", coef[i]);
                }
                else {
                    if (coef[i] != -1) printf("%d", coef[i]);
                    else putchar('-');
                }
                if (i != 7) printf("x^%d", (8-i));
                else printf("x");
            }
            else if (i != 7) {
                Print_coef(coef[i]);
                printf("x^%d", (8-i));
            }
            else {
                Print_coef(coef[i]);
                printf("x");
            }
        }

        if (i == 8) {
            if (first == 8) {
                printf("%d", coef[i]);
            }
            else {
                if (coef[i] != 0) {
                    if (coef[i] > 0) printf("+");
                    printf("%d", coef[i]);
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int coef[9] = {0};
        for (int j = 0; j < 9; j++) {
            scanf("%d", &coef[j]);
        }
        printf("case #%d:\n", i);
        Print(coef);
    }
    return 0;
}
