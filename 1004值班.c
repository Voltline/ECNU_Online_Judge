#include <stdio.h>
int main()
{
	int days[30] = {0};
	int n, day = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &day);
		while (day != -1) {
			days[day-1] = 1;
			scanf("%d", &day);
		}
	}
	int sign = 1;
	for (int i = 0; i < 30; i++) {
		if (!days[i]) {
			printf("no");
			sign = 0;
			break;
		}
	}
	if (sign) {
		printf("yes");
	}
	return 0;
}
