#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

int cnt_one(long long n1);
bool compare(long long n1, long long n2);

int main()
{
	int T{0}, N{0};
	long long input{0};
	vector<long long> ans;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> input;
			ans.push_back(input);
		}
		sort(ans.begin(), ans.end(), compare);
		cout << "case #" << i << ":" << endl;
		for (auto& j : ans) {
			cout << j << " ";
		}
		cout << endl;
		vector<long long>().swap(ans);
	}
	return 0;
}

int cnt_one(long long n1)
{
	string n{bitset<64>(n1).to_string()};
	int cnt{0};
	for (auto& i : n) {
		if (i == '1') cnt++;
	}
	return cnt;
}

bool compare(long long n1, long long n2)
{
	int n1_one{cnt_one(n1)}, n2_one{cnt_one(n2)};
	if (n1_one != n2_one) {
		return n1_one > n2_one;
	}
	else {
		return n1 < n2;
	}
}