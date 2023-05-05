#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int digit[120];
    int size;
} BigInt;

void carry(BigInt* a)
{
    int last = 0;
    for (int i = 119; i >= 0; i--) {
        if (a->digit[i] != 0) {
        	last = i+1;
			break;	
		}
    }
    a->size = last;
    for (int i = 0; i < last; i++) {
        if (a->digit[i] >= 10) {
            a->digit[i+1] += a->digit[i] / 10;
            a->digit[i] %= 10;
            if (i == last-1) {
                a->size++;
            }
        }
    }
}

BigInt Add(BigInt* a, BigInt* b)
{
    BigInt temp = *a;
    for (int i = 0; i < b->size; i++) {
        temp.digit[i] += b->digit[i];
    }
    carry(&temp);
    return temp;
}

BigInt Fibs[121] = {(BigInt){{0}, 1}, (BigInt){{1}, 1}};

void fibs()
{
    for (int i = 2; i < 121; i++) {
        Fibs[i] = Add(&Fibs[i-1], &Fibs[i-2]);
    }
}

void Print(BigInt* a)
{
    for (int i = a->size-1; i >= 0; i--) {
        printf("%d", a->digit[i]);
    }
    printf("\n");
}

int main()
{
    fibs();
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n = 0;
        scanf("%d", &n);
        printf("case #%d:\n", i);
        Print(&Fibs[n]);
    }
    return 0;
}
