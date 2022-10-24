#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	if (a.size() != b.size()) {
		cout << "NO" << endl;
	}
	else {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());		
		if (a == b) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}