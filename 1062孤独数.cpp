#include <iostream>
#include <cstdio>
using namespace std;
constexpr int max_size{1000001};
int array[max_size]{0};

int count(int i)
{
	int sum{i};
	while (i != 0) {
		sum += i%10;
		i /= 10;
	}
	return sum;
}

void solve()
{
	for (int i = 1; i < max_size; i++) {
		array[count(i)] = 1;
	}
}

int main()
{
	solve();
	for (int i = 1; i <= 1000000; i++) {
		if (!array[i]) {
			cout << i << endl;
		}
	}
	return 0;
}
