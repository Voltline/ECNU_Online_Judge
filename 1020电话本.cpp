#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n{0}, opt{0};
	string p, x;
	map<string, vector<string>> ans;
	vector<string> temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> opt >> p;
		if (opt == 0) {
			cin >> x;
			if (ans.find(p) != ans.end()) {
				ans[p].push_back(x);
			}
			else {
				temp.push_back(x);
				ans.insert({p, temp});
			}
		}
		else {
			if (ans.find(p) != ans.end()) {
				ans.erase(ans.find(p));
			}
		}
		vector<string>().swap(temp);
	}
	for (auto& i : ans) {
		cout << i.first << " ";
		for (auto& j : i.second) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}