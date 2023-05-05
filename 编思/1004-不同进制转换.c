#include <stdio.h>
#include <string.h>

char table[] = "0123456789ABCDEF";

char toUpper(char c);
int charToNum(char c);
int toDecimal(char num[], int R);
void toR(int num, int R);
int main()
{
	int A = 0, B = 0;
	char input[40];
	scanf("%d%s%d", &A, input, &B);
	int n = toDecimal(input, A);
	if (n != 0) toR(n, B);
	else putchar('0');
	return 0;
}

char toUpper(char c)
{
	if (c <= 'z' && c >= 'a') return c - 'a' + 'A';
	else {
		return c;
	}
}

int charToNum(char c)
{
	if (c >= '0' && c <= '9') {
		return (c - '0');
	}
	else {
		return toUpper(c) - 'A' + 10;
	}
}

int toDecimal(char num[], int R)
{
	int res = 0, n = strlen(num);
	res += charToNum(num[0]);
	int digit = 0;
	for (int i = 1; i < n; i++) {
		res *= R;
		res += charToNum(num[i]);
	}
	return res;
}

void toR(int n, int R)
{
	if (n != 0) {
		toR(n / R, R);
		printf("%c", table[n % R]);
	}
}