#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int T{0};
	string s, s0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> s >> s0;
		int len1{s.length()}, len2{s0.length()};
		cout << "case #" << i << ":" << endl;
		for (int j = 0; j < len1; j++) {
			if (s.substr(j, len2) == s0) {
				j += len2-1;
			}
			else {
				cout << s[j];
			}
		}
		cout << endl;
	}
	return 0;
}