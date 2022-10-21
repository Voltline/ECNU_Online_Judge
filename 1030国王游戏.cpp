#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

class bigint
{
public: 
	vector<int> nums; // 顺序存，如1234，存为4321
	bool isZero{true};
	
	bigint(const bigint& bn) 
	{
		this->isZero = bn.isZero;
		for (auto& i : bn.nums) {
			this->nums.push_back(i);
		}
	}
	bigint(const int c) 
	{
		if (c != 0) isZero = false;
		int temp{c};
		while (temp != 0) {
			this->nums.push_back(temp%10);
			temp /= 10;
		}
	}
	
	bigint operator=(const int c) 
	{
		return bigint{c};
	}
	
	bigint operator*(const int c)
	{
		bigint ans{*this};
		for (int i = 0; i < ans.nums.size(); i++) {
			ans.nums[i] *= c;
		}

		for (int i = 0; i < ans.nums.size(); i++) {
			if (ans.nums[i] >= 10) {
				if (i != ans.nums.size()-1) {
					ans.nums[i+1] += ans.nums[i]/10;
					ans.nums[i] %= 10;
				}
				else {
					ans.nums.push_back(ans.nums[i]/10);
					ans.nums[i] %= 10;
				}
			}
		}
		return ans;
	}
	
	bigint operator*=(const int c) 
	{
		*this = *this * c;
		return *this;
	}
	
	bigint operator/(const int c)
	{
		bigint ans{*this};
		int x{0};
		for (int i = ans.nums.size()-1; i >= 0; i--) {
			x = 10*x + ans.nums[i];
			ans.nums[i] = x/c;
			x %= c;
		}
		ans.clear_zero();
		return ans;
	}
	
	bool operator<(const bigint bn2)
	{
		if (bn2.nums.size() != this->nums.size()) {
			return this->nums.size() < bn2.nums.size();
		}
		else {
			for (int i = this->nums.size()-1; i >= 0; i--) {
				if (this->nums[i] < bn2.nums[i]) return true;
				else if (this->nums[i] < bn2.nums[i]) return false;
			}
			return false;
		}
	}
	
	void clear_zero()
	{
		for (auto it = this->nums.end(); *it != 0; it--) {
			if (*it == 0) {
				nums.erase(it);
			}
		}
	}
	
	friend ostream& operator<<(ostream& output, bigint bn) 
	{
		if (!bn.isZero) {
			int index{0};
			for (int i = bn.nums.size()-1; i >= 0; i--) {
				if (bn.nums[i] != 0) {
					index = i;
					break;
				}
			}
			for (int i = index; i >= 0; i--) {
				output << bn.nums[i];
			}
		}
		else {
			output << 0;
		}
		return output;
	}	
};

bigint Max(bigint bn1, bigint bn2)
{
	return bn1 < bn2 ? bn2 : bn1;
}

bigint accumulate{1};

class person
{
public:
	int left;
	int right;
};

bool compare(person p1, person p2);

int main()
{
	int n{0}, a{0}, b{0}, a_1{0}, b_1{0};
	cin >> n >> a >> b;
	vector<person> per;
	for (int i = 0; i < n; i++) {
		cin >> a_1 >> b_1;
		per.push_back(person{a_1, b_1});
		accumulate *= a_1;
	}
	sort(per.begin(), per.end(), compare);
	bigint ans{0}, ret{a};
	for (int i = 0; i < n; i++) {
		bigint t{(ret / per[i].right)};
		ans = Max(ans, t);
		ret *= per[i].left;
	}
	cout << ans << endl;
	return 0;
}

bool compare(person p1, person p2)
{
	return (p1.left * p1.right) < (p2.left * p2.right);
}