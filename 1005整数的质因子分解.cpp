#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

bool isPrime(int x);

int main()
{
	int T{0}, a{0};
	vector<int> prime;
	map<int, int> ans;
	for (int i = 2; i <= 20000; i++) {
		if (isPrime(i)) prime.push_back(i);
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a;
		while (a != 1) {
			for (auto& i : prime) {
				if (a % i == 0) {
					if (ans.find(i) != ans.end()) {
						ans.find(i)->second++;
					}
					else {
						ans.insert({i, 1});
					}
					a /= i;
				}
			}
		}
		for (auto& i : ans) {
			cout << "(" << i.first << "," << i.second << ")";
		}
		cout << endl;
		map<int, int>().swap(ans);
	}
	return 0;
}

bool isPrime(int x)
{
	if (x < 2) return false;
	else {
		if (x == 2) return true;
		for (int i = 2; i < sqrt(x) + 1; i++) {
			if (x % i == 0) return false; 
		}
		return true;
	}
}