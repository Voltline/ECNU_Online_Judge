#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;

class People
{
public:
	ll time;
	int index;	
};

bool compare(People p1, People p2);

int main()
{
	int n{0}, T{0};
	vector<People> times;
	ll sum{0};
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> T;
		times.push_back(People{T, i+1});
		//sum += T;
	}
	sort(times.begin(), times.end(), compare);
	for (int i = 0; i < times.size(); i++) {
		sum += times[i].time * (times.size() - i - 1);
	}
	for (auto& i : times) {
		cout << i.index << " ";
	}
	cout << endl;
	cout << fixed << setprecision(2) << (double)sum/(n) << endl;
	return 0;
}

bool compare(People p1, People p2)
{
	if (p1.time != p2.time) return p1.time < p2.time;
	return p1.index < p2.index;
}