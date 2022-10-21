#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T{0};
	string line;
	cin >> T;
	getline(cin, line);
	for (int i = 0; i < T; i++) {
		getline(cin, line);
		for (auto& i : line) {
			if (i != 'Z') {
				i++;
			}
			else {
				i = 'A';
			}
		}
		cout << "case #" << i << ":" << endl;
		cout << line << endl;
	}
	return 0;
}