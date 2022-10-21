#include <iostream>
using namespace std;

int main()
{
	int n{0}, max{0};
	cin >> n;
	int** matrix = new int* [2*n+1];
	for (int i = 0; i < 2*n+1; i++) {
		matrix[i] = new int[2*n+1];
	}
	for (int i = 0; i < 2*n+1; i++) {
		max = n-i;
		for (int j = i; j < 2*n+1-i; j++) {
			matrix[i][j] = max;
			matrix[j][i] = max;
		}
		for (int j = i; j < 2*n+1-i; j++) {
			matrix[2*n-i][j] = max;
			matrix[j][2*n-i] = max;
		}
	}
	for (int i = 0; i < 2*n+1; i++) {
		for (int j = 0; j < 2*n+1; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	delete[] matrix;
	return 0;
}