#include <stdio.h>
#include <math.h>

long long llabs(long long a)
{
    return (a > 0) ? a : -a;
}

int steps(long long x, long long y)
{
    long long a = llabs(x) + llabs(y);
    if (a == 0) return 0;
    else {
        if (a % 2 == 1) {
            return (int)log2(a-1)+1;
        }
        else return -1;
    }
}

void Path(long long x, long long y, int k)
{
    if (k) {
        long long d = 1ll << (k-1);
        if (llabs(x) > llabs(y)) {
            if (x > 0) {
                Path(x-d, y, k-1);
                putchar('E');
            }
            else {
                Path(x+d, y, k-1);
                putchar('W');
            }
        }
        else {
            if (y > 0) {
                Path(x, y-d, k-1);
                putchar('N');
            }
            else {
                Path(x, y+d, k-1);
                putchar('S');
            }
        }
    }
}

int main()
{
    long long x = 0, y = 0;
    int k = 0;
    scanf("%lld%lld", &x, &y);
    k = steps(x, y);
    if (k == -1) {
        printf("-1\n");
    }
    else {
        printf("%d\n", k);
        if (k != 0) Path(x, y, k);
    }
    return 0;
}
