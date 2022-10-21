#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x);

int main()
{
	int n{0};
	cin >> n;
	if (isPrime(n)) {
		cout << "Yes" << endl;
	} 
	else {
		cout << "No" << endl;
	}
	return 0;
}

bool isPrime(int x)
{
	if (x < 2) return false;
	else {
		if (x == 2) return true;
		for (int i = 2; i < sqrt(x) + 1; i++) {
			if (x % i == 0) return false; 
		}
		return true;
	}
}