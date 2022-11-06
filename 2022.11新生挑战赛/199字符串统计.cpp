#include <bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    getline(cin, input);
    int cnt{0};
    for (auto& i : input) {
        if (i <= 'z' && i >= 'a' || i >= 'A' && i <= 'Z') {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
