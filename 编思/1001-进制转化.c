#include <stdio.h>
#include <stdlib.h>

char num[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char res[40] = { '0' };

int main()
{
	int T = 0, sign = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N = 0, R = 0, cnt = 0;
		scanf("%d%d", &N, &R);
		if (N < 0) {
			sign = 1;
			N = -N;
		} 
		while (N > 0) {
			res[cnt++] = num[N % R];
			N /= R;
		}
		if (sign) printf("-");
		for (int i = cnt-1; i >= 0; i--) {
			printf("%c", res[i]);
		}
		printf("\n");
		sign = 0;
	}
	return 0;
}