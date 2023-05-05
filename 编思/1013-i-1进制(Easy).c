#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    long long re; // Real
    long long im; // Imagination
} Complex;

int bit_set[300] = {0};

void Print(long long re, long long im)
{
    long long r = re, i = im;
    if (r != 0) {
        printf("%lld", r);
        if (i > 0) {
            if (i == 1) {
                printf("+i\n");
            }
            else {
                printf("+%lldi\n", i);
            }
        }
        else if (i < 0) {
            if (i == -1) {
                printf("-i\n");
            }
            else {
                printf("%lldi\n", i);
            }
        }
        else {
            printf("\n");
        }
    }
    else {
        if (i != 0) {
            if (i == 1) {
                printf("i\n");
            }
            else if (i == -1) {
                printf("-i\n");
            }
            else {
                printf("%lldi\n", i);
            }
        }
        else printf("0\n");
    }
}

int toBinary(const char* str)
{
    int len = strlen(str);
    int d = 0, cnt = 0;
    for (int i = len - 1; i >= 2; i--) {
        if (str[i] >= 'A') d = str[i] - 'A' + 10;
        else d = str[i] - '0';
        for (int j = 0; j < 4; j++) {
            bit_set[cnt++] = d & 1;
            d >>= 1;
        }
    }
    for (int i = 299; i >= 0; i--) {
        if (bit_set[i] != 0) return i+1;
    }
}

void toDec(int cnt)
{
    long long a = 0, b = 0, qr = 0, qi = 0;
    for (int i = cnt-1; i >= 0; i--) {
        a = -qr - qi + bit_set[i];
        b = qr - qi;
        qr = a;
        qi = b;
    }
    Print(a, b);
}

Complex Mul(Complex c1, Complex c2)
{
    long long re1 = c1.re, im1 = c1.im;
    long long re2 = c2.re, im2 = c2.im;
    return (Complex){re1 * re2 - im1 * im2, re1 * im2 + re2 * im1};
}

int main()
{
    char hex[200] = {0};
    scanf("%s", hex);
    int cnt = toBinary(hex);
    toDec(cnt);
    return 0;
}
