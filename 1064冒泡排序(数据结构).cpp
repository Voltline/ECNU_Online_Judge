#include <iostream>
using namespace std;

int main()
{
	int N{0};
	cin >> N;
	int* array = new int[N];
	for (int i = 0; i < N; i++)  {
		cin >> array[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (array[j] < array[i]) {
				cout << array[i] << " " << array[j] << endl;
				int temp{array[i]};
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	delete[] array;
	return 0;
}