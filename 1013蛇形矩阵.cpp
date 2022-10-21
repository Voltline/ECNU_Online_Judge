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
	bool sign{true}; // true+, false-
	int num{1};
	for (int i = 0; i < n; i++) {
		if (sign) {
			int sum{i};
			for (int j = 0; j <= sum; j++) {
				matrix[j][sum-j] = num++;
			}
			sign = false;
		}
		else {
			int sum{i};
			for (int j = sum; j >= 0; j--) {
				matrix[j][sum-j] = num++;
			}
			sign = true;
		}
	}
	int cnt = 1;
	for (int i = n; i < 2*n-1; i++) {
		if (sign) {
			int sum{i};
			for (int j = cnt; j <= sum-cnt; j++) {
				matrix[j][sum-j] = num++;
			}
			sign = false;
		}
		else {
			int sum{i};
			for (int j = sum-cnt; j >= cnt; j--) {
				matrix[j][sum-j] = num++;
			}
			sign = true;
		}
		cnt++;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}