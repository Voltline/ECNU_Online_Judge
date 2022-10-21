#include <iostream>
using namespace std;

int GCD(int a, int b);
int LCM(int a, int b);

int main()
{
	int N{0}, a{0}, b{0};
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		cout << GCD(a, b) << " " << LCM(a, b) << endl;
	}
	return 0;
}

int GCD(int a, int b)
{
	int n{a}, m{b};
	if (a % b == 0) return b;
	else return GCD(b, (a%b));
}

int LCM(int a, int b)
{
	return (a*b)/GCD(a, b);
}