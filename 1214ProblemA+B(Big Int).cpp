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
	
	bigint operator+(const bigint& bn) 
	{
			
	}
	
	bigint operator=(const int c) 
	{
		return bigint{c};
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

int main()
{
    int A{0}, B{0};
    while (cin >> A >> B) {
        cout << (A+B) << endl;
    }
    return 0;
}