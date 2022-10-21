#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n{0};
    int a{0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        a--;
        bool check{false};
        double temp{sqrt(1+8*a)};
        if ((int)pow((int)temp, 2) == 1+8*a) {
            if ((1+(int)temp)%2 == 0) {
                cout << 1 << endl;
                check = true;
            }
        }
        if (!check) {
            cout << 0 << endl;
        }
    }
    return 0;
}