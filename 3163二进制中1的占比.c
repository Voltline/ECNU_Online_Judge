#include <stdio.h>
int GCD(int a, int b);

int main()
{
	unsigned int n = 0;
	scanf("%u", &n);
	int cnt_one = 0;
	while (n != 0) {
		if (n % 2 == 1) {
			cnt_one++;
		}
		n >>= 1;
	}
	int gcd = GCD(cnt_one, 32);
	printf("%d,%d:%d",cnt_one, cnt_one/gcd, 32/gcd);
	return 0;
}

int GCD(int a, int b)
{
	if (a == 0) {
		return 1;
	}
	else {
		for (int i = a; i >= 1; i--) {
			if (b % i == 0 && a % i == 0) {
				return i;
			}
			else {
				continue;
			}
		}
	}

}