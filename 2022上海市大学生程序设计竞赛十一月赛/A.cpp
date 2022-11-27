#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n{0}, m{0};
	cin >> n >> m;
	int min{0}, max{0};
	int** m1 = new int*[n], **m2 = new int*[n];
	for (int i = 0; i < n; i++) {
		m1[i] = new int[m];
		m2[i] = new int[m];
	}
	int t{1};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			m2[i][j] = 0;
			m1[i][j] = t++;
		}
	}

	int maximum{n*m}, cnt{0};
	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < m; j += 2) {
			m2[i][j] = maximum;
			maximum--;
			cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (m2[i][j] == 0) {
				m2[i][j] = maximum;
				maximum--;
			}
		}
	}
	cout << "1 " << cnt << endl; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << m1[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << m2[i][j] << " ";
		}
		cout << endl;
	}
	delete[] m1;
	delete[] m2;
	return 0;
}