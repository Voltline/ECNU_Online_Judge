#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

string getLower(string word);

int main()
{
	const vector<string> ignore{"the", "a", "an", "of", "for", "and"};
	string line;
	string ans;
	while (getline(cin, line)) {
		for (auto& i : line) {
			if (i == '-') i = ' ';
		}
		istringstream strin(line);
		string temp;
		while (strin >> temp) {
			if (find(ignore.begin(), ignore.end(), getLower(temp)) == ignore.end()) {
				ans.push_back(temp[0]);
			}
		}
		cout << ans << endl;
		ans = "";
	}
	return 0;
}

string getLower(string word)
{
	for (auto& i : word) {
		i = (char)tolower(i);
	}
	return word;
}