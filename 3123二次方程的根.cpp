#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double a{0}, b{0}, c{0};
	while (cin >> a >> b >> c) {
		double delta{pow(b, 2) - 4*a*c};
		if (fabs(delta) < 1e-5) {
			cout << fixed << setprecision(6) << -b/(2*a) << endl;
		}
		else {
			double x1{(-b+sqrt(delta))/(2*a)}, x2{(-b-sqrt(delta))/(2*a)};
			cout << fixed << setprecision(6) << (x1 > x2 ? x2 : x1) 
			<< " " << fixed << setprecision(6) << (x1 > x2 ? x1 : x2) << endl; 
		}
	}
	return 0;	
}