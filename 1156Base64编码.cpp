#include <iostream>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

char map[64];

void init();

int main()
{
	init();
	int T{0};
	string line, binary_line, output_line;
	vector<string> c_list;
	cin >> T;
	getline(cin, line);
	for (int i = 0; i < T; i++) {
		getline(cin, line);
		for (auto& i : line) {
			binary_line.append(bitset<8>(i).to_string());
		}
		while (binary_line.length() % 6 != 0) {
			binary_line.push_back('0');
		}
		for (int j = 0; j < binary_line.length()/6; j++) {
			c_list.push_back(binary_line.substr(j*6, 6));
		}
		int sum{0};
		for (auto& i : c_list) {
			for (auto& j : i) {
				sum *= 2;
				sum += static_cast<int>(j - '0');
			}
			output_line.push_back(map[sum]);
			sum = 0;
		}
		while (output_line.length() % 4 != 0) {
			output_line.push_back('=');
		}
		cout << "case #" << i << ":" << endl;
		cout << output_line << endl;
		string().swap(binary_line);
		string().swap(output_line);
		vector<string>().swap(c_list);
	}
	return 0;
}

void init()
{
	for (int i = 0; i < 26; i++) {
		map[i] = static_cast<char>('A' + i);
	}
	for (int i = 26; i < 52; i++) {
		map[i] = static_cast<char>('a' + i - 26);
	}
	for (int i = 52; i < 62; i++) {
		map[i] = static_cast<char>('0' + i - 52);
	}
	map[62] = '+';
	map[63] = '/';
}