#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int sign;
    int size;
    int digit[200];
} BigInt;

void strToBigInt(const char* s, BigInt* b)
{
    if (s[0] == '-') b->sign = 1;
    else b->sign = 0;

    int len = strlen(s);
    int begin = 0;
    for (int i = len-1; i >= b->sign; i--) {
        b->digit[begin++] = s[i] - '0';
    }
    b->size = begin;
}

void Multiply(BigInt* a, int b)
{
    if (b < 0) a->sign = -1 * a->sign;
    for (int i = 0; i < a->size; i++) {
        a->digit[i] *= b;
    }
    
    int carry = 0, size = a->size;
    for (int i = 0; i < size; i++) {
        a->digit[i+1] += a->digit[i] / 10;
        a->digit[i] %= 10;
    }
    if (a->digit[size] != 0) {
    	a->size++;
		size++;	
	}
    
    if (a->digit[size] != 0) {
        carry = a->digit[size] / 10;
        if (carry >= 1) {
            a->digit[size] = a->digit[size] / 10;
            a->digit[size-1] %= 10;
            a->size++;
        }
    }
}

void Pow(BigInt* b, int a, int n)
{
    if (n == 0) {
        return;
    }
    else {
        for (int i = 0; i < n; i++) {
            Multiply(b, a);
        }
    }
}

void Print(BigInt* a)
{
    if (a->sign == 1) printf("-");
    for (int i = a->size-1; i >= 0; i--) {
        printf("%d", a->digit[i]);
    }
    printf("\n");
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int a = 0, n = 0;
        scanf("%d%d", &a, &n);
        BigInt b = {0, 1, {1}};
        Pow(&b, a, n);
        printf("case #%d:\n", i);
        Print(&b);
    }
    return 0;
}
