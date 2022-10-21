#include <stdio.h>
#include <math.h>

int main()
{
	unsigned long long n;
	scanf("%llu", &n);
	long long n1 = (long long)sqrt((double)n);
	if (n1 * n1 >= n) {
		printf("%lld", n1);
	}
	else {
		printf("%lld", n1 + 1);
	}
	
	return 0;
}

