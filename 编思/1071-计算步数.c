#include <stdio.h>
#include <math.h>
#define labs(x) ((x) < 0) ? -(x) : (x)
int main()
{
    long long x = 0, y = 0;
    scanf("%lld%lld", &x, &y);
    x = labs(x);
    y = labs(y);
    long long distance = x + y;
    if (distance != 0) {
        distance--;
        if (distance % 2 == 1) {
            printf("-1\n");
        }
        else {
            printf("%d\n", (int)log2(distance)+1);
        }
    }
    else printf("0\n");

    return 0;
}
