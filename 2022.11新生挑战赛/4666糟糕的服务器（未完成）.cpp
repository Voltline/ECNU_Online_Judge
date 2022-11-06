#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n{0}, U{0}, L{0}, D{0};
    cin >> n >> U >> L >> D;
    int cnt{0}, x{0}, ans{0};
    deque<bool> x_check;
    bool check{false};
    ll morethanU{0}, lessthanU{1};
    bool isWarning{false};
    cin >> x;
    if (x >= U) {
        check = true;
        morethanU = (ll)check;
        lessthanU = 0;
    }
    else {
        check = false;
        morethanU = (ll)check;
        lessthanU = 1;
    }
    x_check.push_back(check);
    for (int i = 0; i < n-1; i++) {
        cin >> x;
        if (x >= U) {
            check = true;
        }
        else check = false;

        morethanU += (ll)check;
        lessthanU += (ll)(!check);
        if (x_check.size() < D) {
            x_check.push_back(check);
        }
        else {
            morethanU -= (ll)x_check.front();
            lessthanU -= (ll)!x_check.front();
            x_check.pop_front();
            x_check.push_back(check);
        }

        if (!isWarning && x_check.size() == D
            && morethanU == D) {
            ans++;
            isWarning = true;
        }
        else if (isWarning && x_check.size() == D
                 && lessthanU == D) {
            isWarning = false;
        }
    }
    cout << ans << endl;
    return 0;
}
