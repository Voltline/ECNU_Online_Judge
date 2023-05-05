#include <stdio.h>
#include <string.h>

int cToi(char c);
int triToDec(char nums[]);
int main()
{
	int T = 0;
	scanf("%d", &T);
	char s[50] = {0};
	for (int i = 0; i < T; i++) {
		scanf("%s", s);
		printf("case #%d:\n%d\n", i, triToDec(s));
	}
	return 0;
}

int cToi(char c)
{
	switch (c) {
		case '-': return -1;
		case '0': return 0;
		case '1': return 1;
	}
}

int triToDec(char nums[])
{
	int n = strlen(nums);
	int ans = cToi(nums[0]);
	for (int i = 1; i < n; i++) {
		ans *= 3;
		ans += cToi(nums[i]);
	}
	return ans;
}