#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
class stores
{
public:
	string name;
	int index;
	unsigned int sales;
	double price;	
};
bool cmp1(stores a, stores b) {
	if (fabs(a.price-b.price) > 1e-2) 
		return a.price < b.price;
	else return false;
}
bool cmp2(stores a, stores b) {
	if(a.sales != b.sales)
		return a.sales > b.sales;
	else {
		if(fabs(a.price-b.price) > 1e-2)
			return a.price < b.price;
		return a.index < b.index;
	}
}

int main()
{
	int T{0};
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n{0};
		vector<stores> v, ans;
		cin >> n;
		string name;
		unsigned int sales{0};
		double price;
		for (int j = 0; j < n; j++) {
			cin >> name >> sales >> price;
			v.push_back(stores{name, j, sales, price});
		}
		double sale_mid2{0}, price_mid{0};
		sort(v.begin(), v.end(), cmp1);
		if (n % 2 == 0) {
			price_mid = (v[n/2-1].price + v[n/2].price)/2.0;
		}
		else {
			price_mid = v[n/2].price;
		}
		sort(v.begin(), v.end(), cmp2);
		
		
		if (n % 2 == 0) {
			sale_mid2 = v[n/2-1].sales + v[n/2].sales;
		}
		else {
			sale_mid2 = 2*v[n/2].sales;
		}
		for (auto& s : v) {
			if (s.price < price_mid && s.sales*2 > sale_mid2) {
				ans.push_back(s);
			}
		}
		
		cout << "case #" << i << ":" << endl;
		if (!ans.empty()) {
			for (auto& s : ans) {
				cout << s.name << " " << s.sales << " " << s.price << endl;
			}
		}
		else {
			cout << "no recommendation" << endl;
		}		
	}
	return 0;
}