#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(int x);

int main()
{
	uint64_t k = 1000000000;
	bool* prime = new bool[k];
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i < k; i++) {
		prime[i] = true;
	}
	
	int index{1};
	
	while (index < k) {
		while (!prime[index]) {
			index++;
			if (index >= k) break;
		}
		if (index < k) {
			for (int i = 2; index*i < k; i++) {
				prime[i*index] = false;
			}
		}
		index++;
	}
	for (int i = 0; i < k; i++) {
		if (prime[i]){
			if (isPalindrome(i)) {
				printf("%d,",i);
			}
		} 
	}
	cout << endl;
//    int A{0}, B{0};
//	cin >> A >> B;
//	int cnt{0};
//	for (int i = A; i <= B; i++) {
//		if (prime[i] && isPalindrome(i)) {
//			cnt++;
//		}
//	}
//	cout << cnt << endl;

	delete[] prime;
	return 0;
}

bool isPalindrome(int x)
{
	string origin{to_string(x)};
	string rev_num{origin};
	reverse(origin.begin(), origin.end());
	if (origin == rev_num) return true;
	else return false;
}