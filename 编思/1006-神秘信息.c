#include <stdio.h>
#include <string.h>
int main()
{
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		char s[100] = {0};
		scanf("%s", s);
		int a[128] = {0};
		for (int j = 0; j < 128; j++) a[j] = -1;
		int R = 0;
		char* p = s;
		a[*p] = 1;
		while (*(++p) != 0) {
			if (a[*p] == -1) {
				a[*p] = R;
				R = R ? R + 1 : 2;
			}
		}
		if (R < 2) R = 2;
		long long ans = 0;
		p = s;
		ans += a[*p];
		p++;
		while (*p) {
			ans *= R;
			ans += a[*p];
			p++;
		}
		printf("case #%d:\n%lld\n", i, ans);
	}
	return 0;
}