#include <iostream>
#include <vector>
using namespace std;

int C(vector<int> A, vector<int> B);

int main()
{
	int m, n;
	cin >> m >> n;
	int temp;
	vector<int> A, B;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		B.push_back(temp);
	}
	cout << C(A, B);
	return 0;
}

int C(vector<int> A, vector<int> B)
{
	if (A > B) return 1;
	else if (A < B) return -1;
	else return 0;
}