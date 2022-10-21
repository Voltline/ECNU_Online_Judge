#include <stdio.h>
int main()
{
	int n = 0;
	unsigned int a = 0, c = 0, temp = 0;
	scanf("%u%d", &a, &n);
	for (int i = n; i > 0; i--) {
		temp = a % 2;
		c += temp<<(32-i);
		a >>= 1;
	}
	c += a;
	printf("%u\n", c);
	return 0;
}