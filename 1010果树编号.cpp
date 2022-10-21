#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n{0}, s{0}, p{0};
	cin >> n >> s >> p;
	n %= 100;
	string ans;
	string n_str;
	if (n < 10) {
		n_str.push_back('0');
	}
	n_str.append(to_string(n));
	string s_str;
	if (s < 10) {
		s_str.push_back('0');
	}
	s_str.append(to_string(s));
	string p_str;
	if (p < 10) {
		p_str.push_back('0');
	}
	p_str.append(to_string(p));
	ans.append(n_str);
	ans.append(s_str);
	ans.append(p_str);
	cout << ans << endl;
	return 0;
}