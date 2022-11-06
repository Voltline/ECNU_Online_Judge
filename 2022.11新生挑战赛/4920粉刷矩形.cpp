#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n{0}, m{0}, k{0};
    cin >> n >> m >> k;
    char** matrix = new char*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new char[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = '.';
        }
    }

    int row{0}, col{0};
    char color, dire;
    for (int i = 0; i < k; i++) {
        cin >> row >> col >> color >> dire;
        col--;
        row--;
        if (dire == 'R') {
            for (int j = col; j < m; j++) {
                matrix[row][j] = color;
            }
        }
        else if (dire == 'L') {
            for (int j = col; j >= 0; j--) {
                matrix[row][j] = color;
            }
        }
        else if (dire == 'D') {
            for (int i = row; i < n; i++) {
                matrix[i][col] = color;
            }
        }
        else if (dire == 'U') {
            for (int i = row; i >= 0; i--) {
                matrix[i][col] = color;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }


    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
    return 0;
}
