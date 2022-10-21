#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
ll sum{0};

class cow
{
public:
	ll w;
	ll s;
};

bool compare(cow c1, cow c2);

int main()
{
	vector<cow> cows;
	ll weight{0}, strength{0};
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> weight >> strength;
		sum += weight;
		cows.push_back(cow{weight, strength});
	}
	sort(cows.begin(), cows.end(), compare);
	ll ans{-1000000010}, ret{0};
	for (int i = 0; i < N; i++) {
		ll t{ret - cows[i].s};
		ans = max(ans, t);
		ret += cows[i].w;
	}
	cout << ans << endl;
	return 0;
}

bool compare(cow c1, cow c2)
{
	return sum - c1.w - c1.s > sum - c2.w - c2.s;
}
