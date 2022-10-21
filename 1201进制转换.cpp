#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char Charcter[26];

int main()
{
	for (int i = 0; i < 26; i++) {
		Charcter[i] = static_cast<char>('A' + i);
	}
	int T{0}, input{0}, R{0};
	int sign{1};
	string output;
	cin >> T;
	for (int i = 0; i < T; i++) {
		sign = 1;
		cin >> input >> R;
		if (input < 0) {
			sign = -1;
			input = -input;
		}
		while (input > R-1) {
			if (input %R >= 10) {
				output.push_back(Charcter[input%R-10]);
			}
			else {
				output.push_back(static_cast<char>(input%R+48));
			}
			input /= R;
		}
		if (input %R >= 10) {
			output.push_back(Charcter[input%R-10]);
		}
		else {
			output.push_back(static_cast<char>(input%R+48));
		}
		if (sign == -1) {
			output.push_back('-');
		}
		reverse(output.begin(), output.end());
		cout << output << endl;
		string{}.swap(output);
	}
	return 0;
}