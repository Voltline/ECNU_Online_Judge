#include <iostream>
using namespace std;

int main()
{
	int n{0}, sum{0}, line{0}, space{0}, star{0};
	while (cin >> n) {
		sum = 2*n + 1;
		line = n + 1;
		for (int i = 0; i < line; i++) {
			space = sum - 2*i - 1;
			star = sum - space;
			for (int j = 0; j < space/2; j++) {
				cout << " ";
			}
			for (int j = 0; j < star; j++) {
				cout << "*";
			}
			for (int j = 0; j < space/2; j++) {
				cout << " ";
			}
			cout << endl;
		}
		line = n-1;
		for (int i = line; i >= 0; i--) {
			space = sum - 2*i - 1;
			star = sum - space;
			for (int j = 0; j < space/2; j++) {
				cout << " ";
			}
			for (int j = 0; j < star; j++) {
				cout << "*";
			}
			for (int j = 0; j < space/2; j++) {
				cout << " ";
			}	
			cout << endl;
		}
	}
	return 0;
}