#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n{0}, x{0}, y{0};
    cin >> n >> x >> y;
    x--;
    y--;
    if (y - x >= 0) {
        ll up{1};
        for (int i = 1; i < (x-y+n); i++) {
            up += i;
        }
        int delta{x - 0};
        cout << up + delta << endl;
    }
    else {
        ll left{1};
        for (int i = 1; i < n+1; i++) {
            left += i;
        }
        for (int i = n-1; i > (y-x+n); i--) {
            left += i;
        }
        int delta{y - 0};
        cout << left + delta << endl;
    }
    return 0;
}
