#include <iostream>
using namespace std;

unsigned long long tribonacci[75]{0, 1, 1};

int main()
{
	for (int i = 3; i < 75; i++) {
		tribonacci[i]=tribonacci[i-1]+tribonacci[i-2]+tribonacci[i-3];
	}
	int T{0}, n{0};
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << "case #" << i << ":" << endl << tribonacci[n] << endl;
	}
	return 0;
}