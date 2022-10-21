#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N{0}, input{0};
	set<int> ans;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		ans.insert(input);
	}
	cout << ans.size() << endl;
	for (auto& i : ans) {
		cout << i << " ";
	}
	return 0;
}