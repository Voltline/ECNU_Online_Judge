#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    /*顶点位置：
    xL = -xR - 1
    左上：(xL, -xL), (2xR+1)^2 + 2xR + 1
    右上：(xR, xR+1), (2xR+1)^2
    左下：(xL, xL), (-2xL)^2
    右下：(xR, -xR), (2xR+1)^2-2xR-1*/
    ll n{0}, x{0}, y{0};
    cin >> n;
    ll sqrt_n{((ll)sqrt(n)-1)/2}, sqrt_n1{sqrt_n+1};
    if (sqrt_n % 2 == 1) {
        if ((2*sqrt_n+2)*(2*sqrt_n+1) > n) {
            y = sqrt_n+1;
            x = (2*sqrt_n+1)*(2*sqrt_n+1)-n + sqrt_n;
        }
        else if ((2*sqrt_n+2)*(2*sqrt_n+1) < n){
            y = (2*sqrt_n+2)*(2*sqrt_n+1)-n+sqrt_n1;
            x = -sqrt_n1;
        }
        else {
            x =-sqrt_n-1;
            y = sqrt_n+1;
        }
    }
    else {
        if (2*sqrt_n*(2*sqrt_n+1) < n) {
            x = sqrt_n;
            y = 2*sqrt_n*(2*sqrt_n+1)-n -sqrt_n-1;
        }
        else if (2*sqrt_n*(2*sqrt_n+1) > n){
            x = (2*sqrt_n+2)*(2*sqrt_n+1)-n+sqrt_n1;
            y = -sqrt_n1;
        }
        else {
            x = sqrt_n;
            y = -sqrt_n;
        }
    }
    cout << "(" << x << "," << y << ")" << endl;
    return 0;
}
