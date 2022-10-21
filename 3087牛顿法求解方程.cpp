#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double epsilon = 1e-15;

double df(double xn);
double f(double xn);

int main()
{
	double x0{1.5};
	double x1{x0 - f(x0)/df(x0)};
	int cnt{1};
	while (f(x1) >= epsilon) {
		x0 = x1;
		x1 = x0 - f(x0)/df(x0);
		cnt++;
	}
	cout << fixed << setprecision(2) << x1 << " " << cnt << endl;
	return 0;
}

double df(double xn)
{
	return 6*pow(xn, 2)-8*xn+3;
}

double f(double xn)
{
	return 2*pow(xn, 3)-4*pow(xn, 2)+3*xn-6;
}