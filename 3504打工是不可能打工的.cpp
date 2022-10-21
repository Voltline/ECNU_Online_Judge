#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(long long a, long long b);

int main()
{
	int n{0};
	vector<long long> a;
	long long ai{0}, bi{0}, b_sum{0};
	int cnt{0};
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ai;
		a.push_back(ai);
	}
	for (int i = 0; i < n; i++) {
		cin >> bi;
		b_sum += bi;
	}
	sort(a.begin(), a.end(), compare);
	bool check{false};
	for (auto& i : a) {
		b_sum -= i;
		cnt++;
		if (b_sum <= 0) {
			cout << cnt << endl;
			check = true;
			break;	
		}
	}
	if (!check) {
		cout << "Game Over!" << endl;
	}
	return 0;
}

bool compare(long long a, long long b)
{
	return a > b;
}