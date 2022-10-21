#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	int T{ 0 };
	cin >> T;
	string line;
	set<string> ans;
	getline(cin, line);
	for (int i = 0; i < T; i++) {
		getline(cin, line);
		for (auto& c : line) {
			if (c > 122 || c < 97) {
				c = ' ';
			}
		}
		if (line[line.length() - 1] == ' ') {
			line = line.substr(0, line.length() - 1);
		}
		int temp_ptr{ 0 }, len{ 0 };
		istringstream strin(line);
		string temp;
		while (strin >> temp) {
			ans.insert(temp);
		}

		cout << "case #" << i << ":" << endl;
		for (set<string>::iterator it = ans.begin(); it != ans.end(); it++) {
			if (it != --ans.end()) {
				cout << *it << " ";
			}
			else {
				cout << *it << endl;
			}
		}
		set<string>().swap(ans);
	}
	return 0;
}
