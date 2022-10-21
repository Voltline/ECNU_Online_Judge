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
		matrix[i][i] = n;
		for (int j = i+1; j < n; j++) {
			matrix[i][j] = n - (j - i);
			matrix[j][i] = n - (j - i);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	delete[] matrix;
	return 0;
}