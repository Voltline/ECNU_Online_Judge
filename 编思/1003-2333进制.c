#include <stdio.h>
typedef unsigned long long ull;

int ans[20] = {0};

int main()
{
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		ull n = 0;
		int size = 0;
		scanf("%llu", &n);
		if (n != 0) {
			while (n > 0) {
				ans[size++] = n % 2333;
				n /= 2333;
			}
			for (int i = size-1; i >= 0; i--) {
				printf("%d ", ans[i]);
			}
		}
		else {
			printf("0");
		}
		printf("\n");
	}
	return 0;
}