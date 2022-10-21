#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T{0};
	string line;
	cin >> T;
	getline(cin, line);
	for (int i = 0; i < T; i++) {
		getline(cin, line);
		for (int j = 0; j < line.length(); j+=2) {
			line[j] = static_cast<char>(tolower(line[j]));
		}
		cout << "case #" << i << ":" << endl << line << endl;
	}	
	return 0;
}