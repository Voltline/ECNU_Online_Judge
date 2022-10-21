#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

class fish
{
public:
	ll w;
	ll a;
};

bool compare(fish f1, fish f2);

int main()
{
	int n{0};
	ll w{0}, a{0};
	cin >> n;
	vector<fish> fishs;
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &w, &a);
		fishs.push_back(fish{w, a});		
	}
	sort(fishs.begin(), fishs.end(), compare);
	ll x{1}, ret{1}, sum{0};
	for (int i = 0; i < n; i++) {
		if (ret <= fishs[i].w) {
			sum = fishs[i].w - ret;
			ret = fishs[i].w + fishs[i].a;
		}
		else {
			sum = 0;
			ret += fishs[i].a;
		}
		
		if (ret <= 0) {
			sum += (1-ret);
			ret = 1;
		}
		x += sum;
	}
	cout << x << endl;
	return 0;
 }
 
 bool compare(fish f1, fish f2)
 {
	if (f1.a >= 0 && f2.a >= 0) {
 		return f1.w < f2.w;
	}
	else if (f1.a < 0 && f2.a < 0){
		return f1.w+f1.a > f2.w+f2.a;
	}
	else {
		return f1.a > f2.a;
	}
 }