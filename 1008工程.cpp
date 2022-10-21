#include <iostream>
using namespace std;

int main()
{
	int T{ 0 };
	cin >> T;
	int* ans = new int[T];
	for (int i = 0; i < T; i++) {
		int M{ 0 }, K{ 0 }, res{ 0 }, temp{ 0 };
		cin >> M >> K;
		for (int j = 0; j < M; j++) {
			cin >> temp;
			if (j < K) {
				res += temp;
			}
		}
		ans[i] = res;
	}
	for (int i = 0; i < T; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}