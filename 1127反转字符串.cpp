#include <iostream>
#include <string>
using namespace std;

int main()
{
	string line, reversed_line;
	while (getline(cin, line)) {
		reversed_line = line;
		for (int i = line.length()-1; i >= 0; i--) {
			reversed_line[line.length()-1-i] = line[i];
		}
		cout << reversed_line << endl;
	}
	return 0;
}