#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    // a 兔, b 鸡, c猫
    // a + b + c = x
    // 4a + 2b + 3c = y
    // 3a + 3b + 3c = 3x
    // a - b = y - 3x
    // check c >= 0?
    int T{0};
    ll x{0}, y{0};
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> x >> y;
        ll min_a{x+y}, max_a{0};
        ll a{0}, b{0}, c{0};
        for (ll a = 0; a <= x; a++) {
            b = a - y + 3*x;
            c = x - a - b;
            if (b >= 0 && c >= 0) {
                if (min_a > a) min_a = a;

                if (max_a < a) max_a = a;
            }
        }
        cout << min_a << " " << max_a << endl;
    }
    return 0;
}
