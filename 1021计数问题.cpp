#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n{0}, temp{0};
	cin >> n;
	map<int, int> ans;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (ans.find(temp) == ans.end()) {
			ans.insert({temp, 1});
		}
		else {
			ans.find(temp)->second++;
		}
	}
	for (auto& i : ans) {
		cout << i.first << " " << i.second << endl;
	}
	return 0;
}