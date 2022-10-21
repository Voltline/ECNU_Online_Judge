#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T{ 0 };
	cin >> T;
	string line_A, line_B;
	getline(cin, line_A);
	for (int i = 0; i < T; i++) {
		getline(cin, line_A);
		getline(cin, line_B);
		int pos = line_A.find(line_B);
		if (pos != -1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}