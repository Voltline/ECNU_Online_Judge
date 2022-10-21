#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

bool compare(string strA, string strB);

int main()
{
	int T{0}, n{0};
	string str_input;
	vector<string> inputs;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> str_input;
			inputs.push_back(str_input);
		}
		sort(inputs.begin(), inputs.end(), compare);
		cout << "case #" << i << ":" << endl;
		for (auto& j : inputs) {
			cout << j << endl;
		}
		vector<string>().swap(inputs);
	}
	return 0;	
}

bool compare(string strA, string strB)
{
	set<char> strA_set, strB_set;
	for (auto& i : strA) {
		strA_set.insert(i);
	}
	for (auto& i : strB) {
		strB_set.insert(i);
	}
	
	if (strA_set.size() != strB_set.size()) {
		return strA_set.size() > strB_set.size();
	}
	else {
		return strA < strB;
	}
}