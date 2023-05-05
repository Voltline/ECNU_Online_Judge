#include <iostream>
using namespace std;

int main()
{
	int T{0}, n{0};
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		int max_size{(n / 13) * 5};
		max_size += (n % 13) <= 5 ? (n % 13) : 5;
		cout << max_size << endl;
	}
	return 0;
}