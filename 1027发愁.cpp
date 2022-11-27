#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class team
{
public:
	int score;
	int victory;
	int defeat;
	int index;
	team(int index)
	{
		score = 0;
		victory = 0;
		defeat = 0;
		this->index = index;
	}
};

bool cmp(team a, team b)
{
	if (a.score != b.score) {
		return a.score > b.score;
	}
	else {
		if (a.victory != b.victory) {
			return a.victory > b.victory;
		}
		else {
			if (a.defeat != b.defeat) {
				return a.defeat < b.defeat;
			}
			else {
				return a.index < b.index;
			}
		}
	}
}

int main()
{
	int n{-1}, m{-1};
	while (n != 0) {
		cin >> n >> m;
		if (n != 0) {
			vector<team> v;
			for (int i = 0; i < n; i++) {
				v.push_back(team{i+1});
			}
			for (int i = 0; i < m; i++) {
				int a{0}, b{0}, c{0};
				cin >> a >> b >> c;
				if (c == 1) {
					v[a-1].victory++;
					v[a-1].score += 3;
					v[b-1].defeat++;
					v[b-1].score -= 1;
				}
				else if (c == -1) {
					v[b-1].victory++;
					v[b-1].score += 3;
					v[a-1].defeat++;
					v[a-1].score -= 1;
				}
				else {
					v[a-1].score++;
					v[b-1].score++;
				}
			}
			sort(v.begin(), v.end(), cmp);
			for (int i = 0; i < v.size(); i++) {
				if (i != v.size()-1) {
					cout << v[i].index << " ";
				}
				else cout << v[i].index << endl;
			}
		}
	}
	return 0;
}