#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n{0};
	cin >> n;
	int opt{0}, x{0};
	set<int> ans;
	for (int i = 0; i < n; i++) {
		cin >> opt >> x;
		if (opt == 0) {
			ans.insert(x);
		}
		else {
			ans.erase(x);
		}
	}	
	for (auto& i : ans) {
		cout << i << " ";
	}
	return 0;
}