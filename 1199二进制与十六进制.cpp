#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string tohex(int n);
string tobin(int n);

int main()
{
	int T{0}, N{0};
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << "case #" << i << ":" << endl
		<< tobin(N) << " " << tohex(N) << endl;
	}
	return 0;
}

string tohex(int n)
{
	string hex = "0123456789ABCDEF";
	string ans = "";
	do {
		ans += hex[n % 16];
		n /= 16;
	} while (n != 0);
	reverse(ans.begin(), ans.end());
	return ans;
}

string tobin(int n)
{
	string ans = "";
	do {
		ans += (n % 2) + '0';
		n /= 2;
	} while (n != 0);
	reverse(ans.begin(), ans.end());
	return ans;
}