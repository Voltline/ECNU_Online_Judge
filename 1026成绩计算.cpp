#include <iostream>
using namespace std;

int main()
{
	int T{0}, score{0}, average{0}, min{100}, max{0}, cnt{0};
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> score;
		while (score != -1) {
			if (min > score) min = score;
			if (max < score) max = score;
			average += score;
			cnt++;
			cin >> score;
		}
		cout << "case #" << i << ":" << endl
		<< max << endl
		<< min << endl
		<< average/cnt << endl;
		cnt = 0;
		average = 0;
		min = 100;
		max = 0;
	}
	
	return 0;
}