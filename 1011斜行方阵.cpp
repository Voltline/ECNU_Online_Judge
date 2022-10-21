#include <iostream>
using namespace std;

int main()
{
	int n{0};
	cin >> n;
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}
	int num{1};
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < n-i; j++) {
			matrix[j][i+j] = num;
			num++;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			matrix[i+j][j] = num;
			num++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}