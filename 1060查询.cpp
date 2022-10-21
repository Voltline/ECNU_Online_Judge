#include <iostream>
using namespace std;

int main()
{
	int m{0}, n{0}, x{0};
	cin >> m;
	int* array = new int[501];
	for (int i = 0; i < m; i++) {
		cin >> x;
		array[x] = 1;
	}
	cin >> n;
	for (int j = 0; j < n; j++) {
		cin >> x;
		if (array[x] != 0) cout << "yes!" << endl;
		else cout << "no!" << endl;
	}
	delete[] array;
	return 0;
}
