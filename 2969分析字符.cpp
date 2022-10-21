#include <iostream>
#include <string>
using namespace std;

class Data
{
public:
	int cap_char;
	int low_char;
	int space;
	int digit;
	int other;
};

int main()
{
	int T{ 0 }, cap_char{ 0 }, low_char{ 0 };
	int space{ 0 }, digit{ 0 }, other{ 0 };
	Data result[10]{ {0, 0, 0, 0, 0} };
	string line;
	cin >> T;
	getline(cin, line);
	for (int i = 0; i < T; i++) {
		getline(cin, line);
		for (auto& i : line) {
			if (i >= '0' && i <= '9') {
				digit++;
			}
			else if (i >= 'A' && i <= 'Z') {
				cap_char++;
			}
			else if (i >= 'a' && i <= 'z') {
				low_char++;
			}
			else if (i == ' ') {
				space++;
			}
			else {
				other++;
			}
		}
		result[i] = Data{ cap_char,low_char,space,digit,other };
		cap_char = 0, low_char = 0, space = 0, digit = 0, other = 0;
	}
	for (int i = 0; i < T; i++) {
		cout << "case #" << i << ":" << endl
			<< result[i].cap_char << " "
			<< result[i].low_char << " "
			<< result[i].space << " "
			<< result[i].digit << " "
			<< result[i].other << endl;
	}
	return 0;
}