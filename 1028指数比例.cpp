#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

bool compare(double d1, double d2);

int main()
{
	int T{0}, n{0};
	vector<double> data;
	double ans{0}, input;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> input;
			data.push_back(input);
			ans += exp(input);
		}
		double pivot{0.5/n};
		sort(data.begin(), data.end(), compare);
		cout << "case #" << i << ":" << endl;
		for (int j = 0; j < data.size(); j++) {
			if (exp(data[j])/ans >= pivot) {
				cout << fixed << setprecision(2) << data[j] << endl;
			}
		}
		vector<double>().swap(data);
		ans = 0;
	}
	
	return 0;
}

bool compare(double d1, double d2)
{
	return d1 > d2;
}