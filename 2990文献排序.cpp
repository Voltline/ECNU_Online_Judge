#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class NewString
{
public:
	string original;
	NewString() = default;
	NewString(string s) : original(s) {};
	friend bool operator<(const NewString& s1, const NewString& s2)
	{
		string s1_str = s1.original;
		string s2_str = s2.original;
		transform(s1_str.begin(), s1_str.end(), s1_str.begin(), ::tolower);
		transform(s2_str.begin(), s2_str.end(), s2_str.begin(), ::tolower);
		return s1_str < s2_str;
	}
	friend ostream& operator<<(ostream& output, const NewString& s1)
	{
		output << s1.original;
		return output;
	}
	friend istream& operator>>(istream& input, NewString& s2)
	{
		getline(cin, s2.original);
		return input;
	}
};

int main()
{
	int T = 0, n = 0;
	string buffer;
	cin >> T;
	getline(cin, buffer);
	for (int case_num = 0; case_num < T; case_num++) {
		cout << "case #" << case_num << ":" << endl;
		cin >> n;
		getline(cin, buffer);
		vector<NewString> ans;
		NewString ns1 = {};
		for (int i = 0; i < n; i++) {
			cin >> ns1;
			ans.push_back(ns1);
		}
		sort(ans.begin(), ans.end());
		for (auto& i : ans) {
			cout << i << endl;
		}
	}
	return 0;
}