#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class solve
{
public:
	char c;
	int times;	
};

bool compare(solve s1, solve s2);

int main()
{
	vector<solve> ans;
	int all_times{0};
	for (int i = 0; i < 26; i++) {
		ans.push_back(solve{static_cast<char>('a'+i), 0});
	}
	string line;
	getline(cin, line);
	for (auto& i : line) {
		if (i != ' ') {
			ans[static_cast<int>(i - 'a')].times++;
			all_times++;
		}
	}
	sort(ans.begin(), ans.end(), compare);
	cout << ans[0].c << " " << fixed << setprecision(2) << static_cast<double>(ans[0].times)/all_times << endl;
	return 0;
}

bool compare(solve s1, solve s2)
{
	if (s1.times != s2.times) {
		return s1.times > s2.times;
	}
	else {
		return s2.c > s1.c;
	}
}