#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int seconds{0}, sec{0}, min{0}, hr{0};
	cin >> seconds;
	while (seconds != -1) {
		sec = seconds % 60;
		seconds /= 60;
		min = seconds % 60;
		hr = seconds / 60;
		cout << setw(2) << setfill('0') << hr << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << sec << endl;
		cin >> seconds;
	}
	
	return 0;
}