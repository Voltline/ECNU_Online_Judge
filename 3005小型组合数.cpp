#include <iostream>
#include <cmath>
using namespace std;

unsigned long long C(int n, int m);

int main()
{
	int T{0}, n{0}, m{0};
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> m;
		cout << "case #" << i << ":" << endl
		<< C(n, m) << endl;
	}
	return 0;
}

unsigned long long C(int n, int m)
{
	unsigned long long ans = 0;
	unsigned long long nominator = 1, denominator = 1;
	for (int i = n; i >= n-m+1; i--) {
		nominator *= i;
	}
	for (int i = 1; i <= m; i++) {
		denominator *= i;
	}
	ans = nominator / denominator;
	return ans;
}