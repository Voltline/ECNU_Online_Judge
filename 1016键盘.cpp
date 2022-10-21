#include <iostream>
#include <algorithm>
using namespace std;
using cases = struct
{
public:
	int num;
	int cost;
};

int main()
{
	int T{ 0 }, a{ 0 }, b{ 0 }, c{ 0 }, m{ 0 };
	int USB[300]{ 0 }, PS2[300]{ 0 };
	int USB_num{ 0 }, PS2_num{ 0 }, price{ 0 };
	int computer_cnt{ 0 }, cost_cnt{ 0 };
	string category;
	cases solution[10]{ {0, 0} }, case_temp{ 0, 0 };
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b >> c;
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> price >> category;
			if (category == "USB"s) {
				USB[USB_num] = price;
				USB_num++;
			}
			else {
				PS2[PS2_num] = price;
				PS2_num++;
			}
		}
		sort(USB, USB + USB_num);
		sort(PS2, PS2 + PS2_num);
		int temp_USB_num{ USB_num }, temp_PS2_num{ PS2_num };
		for (int k = 0; k < min(USB_num, a); k++) {
			computer_cnt++;
			cost_cnt += USB[k];
			USB[k] = 0;
			temp_USB_num--;
		}
		for (int k = 0; k < min(PS2_num, b); k++) {
			computer_cnt++;
			cost_cnt += PS2[k];
			PS2[k] = 0;
			temp_PS2_num--;
		}
		int temp_keyboard[300]{ 0 };
		for (int k = 0; k < temp_USB_num; k++) {
			temp_keyboard[k] = USB[k + USB_num - temp_USB_num];
		}
		for (int k = 0; k < temp_PS2_num; k++) {
			temp_keyboard[k + temp_USB_num] = PS2[k + PS2_num - temp_PS2_num];
		}
		sort(temp_keyboard, temp_keyboard + temp_PS2_num + temp_USB_num);
		for (int k = 0; k < min(temp_USB_num + temp_PS2_num, c); k++) {
			computer_cnt++;
			cost_cnt += temp_keyboard[k];
			temp_keyboard[k] = 0;
		}

		solution[i] = cases{computer_cnt, cost_cnt};

		for (int i = 0; i < USB_num; i++) {
			USB[i] = 0;
		}
		for (int i = 0; i < PS2_num; i++) {
			PS2[i] = 0;
		}
		USB_num = 0;
		PS2_num = 0;
		computer_cnt = 0;
		cost_cnt = 0;
	}
	for (int i = 0; i < T; i++) {
		cout << "case #" << i << ": " << endl
			<< solution[i].num << " " << solution[i].cost
			<< endl;
	}
	return 0;
}