#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    double height = 0;
    const double g = 9.8;
    if (n <= 3) {
        height = (n-1)*5 + 1.75;
    }
    else {
        height = 10 + (n-2)*3 + 1.75;
    }
    double t = sqrt(2*height/g);
    printf("%.3f\n",t);
    return 0;
}