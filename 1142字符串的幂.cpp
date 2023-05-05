#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T{0};
    cin >> T;
    for (int i = 0; i < T; i++) {
        string in;
        int times = 0;
        cin >> in >> times;
        cout << "case #" << i << ":" << endl;
        if (times == 0) {
            cout << "" << endl;
        }
        else {
            for (int j = 0; j < times; j++) {
                cout << in;
            }
            cout << endl;
        }
    }
    return 0;
}
