#include <stdio.h>
#define MAX(x, y) ((x) > (y)) ? (x) : (y)
#define MIN(x, y) ((x) < (y)) ? (x) : (y)
typedef long long ll;

ll solve(ll x, ll y)
{
    if (x == 0 || y == 0) return 0;
    if (x == y) {
        return 2*(x+y);
    }
    else {
        ll maximum = MAX(x, y), minimum = MIN(x, y);
        return 4 * (maximum/minimum) * minimum + solve(maximum % minimum, minimum);
    }
}

int main()
{
    ll x = 0, y = 0;
    scanf("%lld%lld", &x, &y);
    printf("%lld\n", solve(x, y));
    return 0;
}
