#include <stdio.h>
#include <math.h>

int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) != -1) {
	    printf("%.3f\n",sqrt((double)(a*a + b*b)));
	}
	return 0;
}