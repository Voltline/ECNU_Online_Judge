#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int T{ 0 }, result[10]{ 0 }, word_times{ 0 };
	string s, t;
	cin >> T;
	getline(cin, s);
	for (int i = 0; i < T; i++) {
		getline(cin, s);
		getline(cin, t);
		int cnt{ 0 };
		for (int i = 0; i < s.length(); i++) {
			if (s.length() == 1) {
				if (s == t) {
					word_times++;
					cnt = 0;
				}
			}
			else {
				if (i != s.length() - 1) {
					if (s[i] != ' ') {
						cnt++;
					}
					else {
						if (s.substr(i - cnt, cnt) == t) {
							word_times++;
						}
						cnt = 0;
					}
				}
				else {
					cnt++;
					if (s.substr(i - cnt + 1, cnt) == t) {
						word_times++;
					}
					cnt = 0;
				}
			}

		}
		result[i] = word_times;
		word_times = 0;
	}
	for (int i = 0; i < T; i++) {
		cout << "case #" << i << ":" << endl
			<< result[i] << endl;
	}
	return 0;
}