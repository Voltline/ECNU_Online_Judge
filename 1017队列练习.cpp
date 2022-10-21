#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> ans;
	int n{0}, opt{0}, x{0};
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> opt;
		switch (opt) {
			case 0:
				cin >> x;
				ans.push_front(x);
				break;
			case 1:
				if (!ans.empty())
					ans.pop_front();
				break;
			case 2:
				cin >> x;
				ans.push_back(x);
				break;
			case 3:
				if (!ans.empty())
					ans.pop_back();
				break;
		}
	}
	for (auto& i : ans) {
		cout << i << " ";
	}
	return 0;
}