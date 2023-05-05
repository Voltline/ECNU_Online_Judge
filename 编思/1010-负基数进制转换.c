#include <stdio.h>
#include <stdlib.h>

char Table[] = "0123456789ABCDEFGHIJ";

void DecimalToR(int N, int R)
{
	if (N != 0) {
		if (N % R >= 0) {
			DecimalToR(N / R, R);
			printf("%c", Table[N % R]);
		}
		else {
			DecimalToR(N/R + 1, R);
			printf("%c", Table[N % R - R]);
		}
	}
}

int main()
{
	int N = 0, R = 0;
	scanf("%d%d", &N, &R);
	if (N == 0) {
		printf("0");
	}
	else {
		DecimalToR(N, R);
	}
	return 0;
}