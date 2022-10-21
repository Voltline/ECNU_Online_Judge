#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

class cow
{
public:
	ll p;
	ll c;
	bool isBought;
};

bool compare(cow c1, cow c2);
bool compare2(cow c1, cow c2);

int main()
{
	int N{0}, K{0};
	vector<cow> cows;
	vector<cow> cows_origin;
	ll p{0}, c{0}, M{0};
	cin >> N >> K >> M;
	for (int i = 0; i < N; i++) {
		cin >> p >> c;
		cows.push_back(cow{p, c, false});
	}
	
	sort(cows.begin(), cows.end(), compare);
	
	ll cnt{0};
	for (int i = 0; i < cows.size(); i++) {
		if (K > 0) {
			if (M > cows[i].c) {
				M -= cows[i].c;
				cows[i].isBought = true;
				cnt++;	
			}
			else {
				break;
			}
		}
		else {
			sort(cows.begin(), cows.end(), compare2);
			break;
		}
	}
	for (int i = 0; i < cows.size(); i++) {
		if (!cows[i].isBought) {
			M -= cows[i].p;
			cows[i].isBought = true;
			cnt++;
		}
		else {
			break;
		}
	}
	cout << cnt << endl;
	return 0;
}

bool compare(cow c1, cow c2)
{
	ll minus1{c1.p - c1.c}, minus2{c2.p - c2.c};
	if (minus1 != minus2) {
		return minus1 > minus2;
	}
	else {
		return c1.c < c2.c;
	}
}

bool compare2(cow c1, cow c2)
{
	return c1.p < c2.p;
}