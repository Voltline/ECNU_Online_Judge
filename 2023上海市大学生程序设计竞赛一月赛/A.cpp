#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int n{0};
	cin >> n;
	map<string, bool> f;
	for (int i = 0; i < n; i++) {
		string name, another;
		cin >> name >> another;
		if (another == "No" && f.find(name) == f.end()) {
			f.insert({name, false});
		}
		else if (another != "No") {
			if (f.find(name) == f.end()) {
				f.insert({name, true});
			}
			if (f.find(another) == f.end()) {
				f.insert({another, true});
			}
			else {
				f[another] = true;
			}
		}
	}
	int cnt{0};
	for (auto& p : f) {
		if (!p.second) cnt++; 
	}
	cout << cnt << endl;
	return 0;
}