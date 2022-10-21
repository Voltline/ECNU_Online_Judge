#include <iostream>
#include <string>
#include <map>
using namespace std;

string stopn(string line);

int main()
{
	int n{0};
	string input;
	map<string, int> ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		string key{stopn(input)};
		if (ans.count(stopn(input))) {
			ans[key]++;
		}
		else {
			ans.insert({key, 1});
		}
	}
	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}

string stopn(string line)
{
	string temp, output;
	for (auto& i : line) {
		if (i != '-') {
			temp.push_back(i);
		}
	}
	for (auto& i : temp) {
		if (i == 'A' || i == 'B' || i == 'C') {
			i = '2';
		}
		else if (i == 'D' || i == 'E' || i == 'F') {
			i = '3';
		}
		else if (i == 'G' || i == 'H' || i == 'I') {
			i = '4';
		}
		else if (i == 'J' || i == 'K' || i == 'L') {
			i = '5';
		}
		else if (i == 'M' || i == 'N' || i == 'O') {
			i = '6';
		}
		else if (i == 'P' || i == 'Q' || i == 'R' || i == 'S') {
			i = '7';
		}
		else if (i == 'T' || i == 'U' || i == 'V') {
			i = '8';
		}
		else if (i == 'W' || i == 'X' || i == 'Y' || i == 'Z') {
			i = '9';
		}
	}
	output = temp.substr(0, 4) + "-" + temp.substr(4, 4);
	return output;
}