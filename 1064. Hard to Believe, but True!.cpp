#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool check(string a1, string a2, string ans);

int main()
{
	string a1, a2, ans;
	string line;
	char input;
	getline(cin, line);
	while (line != "0+0=0") {
		a1 = line.substr(0, line.find('+'));
		a2 = line.substr(line.find('+')+1, line.find('=')-line.find('+')-1);
		ans = line.substr(line.find('=')+1, line.length()-line.find('='));
		if (check(a1, a2, ans)) cout << "True" << endl;
		else cout << "False" << endl;
		getline(cin, line);
	}
	cout << "True" << endl;
	return 0;
}

bool check(string a1, string a2, string ans)
{
	reverse(a1.begin(), a1.end());
	reverse(a2.begin(), a2.end());
	reverse(ans.begin(), ans.end());
	int a1i{stoi(a1)}, a2i{stoi(a2)}, ansi{stoi(ans)};
	if (a1i + a2i == ansi) return true;
	else return false;	
}
