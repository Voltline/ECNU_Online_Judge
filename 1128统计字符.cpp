#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T{0}, character{0}, number{0}, others{0};
	string line;
	cin >> T;
	getline(cin, line);
	for (int i = 0; i < T; i++) {
		getline(cin, line);
		for (auto& i : line) {
			if (i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z') {
				character++;
			}
			else if (i >= '0' && i <= '9') {
				number++;
			}
			else {
				others++;
			}
		}
		cout <<  "character:" << character << endl
		<< "number:" << number << endl
		<< "others:" << others << endl;
		character = 0;
		number = 0;
		others = 0;
	}
	return 0;
}