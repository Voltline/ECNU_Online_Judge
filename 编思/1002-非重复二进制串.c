#include <stdio.h>

int main()
{
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n = 0, cnt = 1, last = 0, max_cnt = 1;
		scanf("%d", &n);
		last = n & 1;
		n >>= 1;
		while (n != 0) {
			if ((n & 1) != last) {
				cnt++;
				if (cnt > max_cnt) max_cnt = cnt;
			}
			else {
				cnt = 1;
			}
			last = n & 1;
			n >>= 1;
		}
		printf("case #%d:\n%d\n", i, max_cnt);
	}
	return 0;
}