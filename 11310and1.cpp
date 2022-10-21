#include <iostream>
using namespace std;

int main()
{
	int N{0}, M{0}, zeros{0}, ones{0};
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		while (M != 0) {
			if (M % 2 == 0) {
				zeros++;
			}
			else {
				ones++;
			}
			M >>= 1;
		}
		cout << zeros << " " << ones << endl;
		zeros = 0;
		ones = 0;
	}
	return 0;
}