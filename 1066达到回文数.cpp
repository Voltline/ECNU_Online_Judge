#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int getReversedInt(int x);
bool isPalindrome(int x);

int main()
{
	int n{0}, m{0}, cnt{0};
	cin >> n;
	while (!isPalindrome(n)) {
		m = getReversedInt(n);
		n += m;
		cnt++;
	}
	cout << cnt << " " << n << endl;
	return 0;
}

int getReversedInt(int x)
{
	vector<int> nums;
	int temp{x}, new_num{0};
	while (temp > 9) {
		nums.push_back(temp%10);
		temp /= 10;
	}
	nums.push_back(temp);
	for (int i = 0; i < nums.size(); i++) {
		new_num += nums[i] * pow(10, nums.size() - i - 1);
	}
	return new_num;
}

bool isPalindrome(int x)
{
	int new_num{getReversedInt(x)};
	if (new_num == x) {
		return true;
	}
	else {
		return false;
	}
}