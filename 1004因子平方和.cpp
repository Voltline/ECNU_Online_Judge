#include <iostream>
using namespace std;

int main()
{
	int T{0}, n{0}, sum{0};
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 2; j < n; j++) {
			if (n % j == 0) {
				sum += j * j;
			}
		}
		cout << "case #" << i << ":" << endl 
		<< sum << endl;
		sum = 0; 	
	}
	return 0;
}