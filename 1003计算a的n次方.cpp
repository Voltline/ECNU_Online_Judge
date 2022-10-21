#include <iostream>
using namespace std;

long long pow(long long a, long long n);

int main()
{
	int T;
	long long a = 0, n = 0;
	cin >> T;
	
	long long* cases = new long long[T];

	for (int i = 0; i < T; i++) {
		cin >> a >> n;
		cases[i] = pow(a, n);
	}
	for (int i = 0; i < T; i++) {
		cout << "case #" << i << ":" << endl;
		cout << cases[i] << endl;
	}
	delete[] cases;
	return 0;
}

long long pow(long long a, long long n)
{
	long long ans{ 1 };
	for (long long i = 0; i < n; i++) {
		ans *= a;
	}
	return ans;
}
