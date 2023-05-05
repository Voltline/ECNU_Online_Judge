#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
	if (a % b) return gcd(b, a % b);
	else return b;
}

int cnt_digit(char c)
{
	int c_i = (int)c;
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		cnt += c_i & 1;
		c_i >>= 1;
	}
	return cnt;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	getchar();
	char s[300] = {0};
	for (int i = 0; i < n; i++) {
		gets(s);
		int sum = 0;
		int len = strlen(s);
		for (int j = 0; j < len; j++) {
			sum += cnt_digit(s[j]);
		}
		int m = gcd(sum, len * 8);
		printf("%d/%d\n", sum / m, len * 8 / m);
	}

	return 0;
}