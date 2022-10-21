#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N{0}, n_nums{0}, b_nums{0}, a_nums{0};
	string line;
	cin >> N;
	getline(cin, line);
	for (int i = 0; i < N; i++) {
		getline(cin, line);
		for (auto& i : line) {
			if (i == 'N') n_nums++;
			else if (i == 'B') b_nums++;
			else if (i == 'A') a_nums++;
		}
		cout << "case #" << i << ":" << endl;
		while (n_nums + b_nums + a_nums != 0) {
			if (n_nums != 0) {
				cout << "N";
				n_nums--;
			}
			
			if (b_nums != 0) {
				cout << "B";
				b_nums--;
			}
			
			if (a_nums != 0) {
				cout << "A";
				a_nums--;
			}
		}
		cout << endl;
	}
	return 0;
}