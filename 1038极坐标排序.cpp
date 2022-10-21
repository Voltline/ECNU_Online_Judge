#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

const double PI = 3.1415926535;

class Point
{
public:
	double x;
	double y;
	double r;
	double theta;
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		this->r = sqrt(x*x + y*y);
		double t = atan2(y, x);
		if (t >= 0) this->theta = t;
		else this->theta = t + 2*PI;
	}
};

bool compare(Point p1, Point p2);

int main()
{
	int T{0}, N{0};
	double x{0}, y{0};
	vector<Point> ans;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> x >> y;
			ans.push_back(Point{x, y});
		}
		sort(ans.begin(), ans.end(), compare);
		cout << "case #" << i << ":" << endl;
		for (auto& j : ans) {
			cout << "(" << fixed << setprecision(4) << j.r 
			<< "," << fixed << setprecision(4) << j.theta 
			<< ")" << endl;
		}
		vector<Point>().swap(ans);
	}
	return 0;
}

bool compare(Point p1, Point p2)
{
	if (fabs(p1.theta-p2.theta) > 1e-8)
	{
		return p1.theta < p2.theta;
	}
	else {
		return p1.r > p2.r;
	}
}