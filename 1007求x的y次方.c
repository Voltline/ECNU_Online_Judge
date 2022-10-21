#include <stdio.h>
#include <math.h>

int main()
{
	double x, y;
	while (scanf("%lf %lf", &x, &y) != -1) {
	    printf("%.3f\n",pow(x, y));
	}
	return 0;
}