#include <iostream>
#include <string>
using namespace std;

const string words_ignore[]{ "the"s, "a"s, "an"s, "of"s, "for"s, "and"s };

bool find_ignore(string word);

int main()
{
	string word;
	int T{ 0 }, cases[10]{ 0 }, temp_cnt{ 0 }, temp_ptr{ -1 }, word_cnt{ 0 };
	cin >> T;
	getchar();
	for (int i = 0; i < T; i++) {
		getline(cin, word);
		for (int j = 0; j < word.length(); j++) {
			word[j] = tolower(word[j]);
		}
		int cnt{ 0 };
		for (int j = 0; j < word.length(); j++) {
			temp_ptr++;
			if (j != word.length() - 1) {
				if (word[j] != ' ') {
					temp_cnt++;
				}
				else {
					if (!find_ignore(word.substr(temp_ptr - temp_cnt, temp_cnt))) {
						word_cnt++;
					}
					temp_cnt = 0;
				}
			}
			else {
				if (word[j] != ' ') {
					temp_ptr++;
					temp_cnt++;
					if (!find_ignore(word.substr(temp_ptr - temp_cnt, temp_cnt))) {
						word_cnt++;
					}
					cases[i] = word_cnt;
					temp_cnt = 0;
					temp_ptr = -1;
					word_cnt = 0;
				}
			}
		}
	}
	for (int i = 0; i < T; i++) {
		cout << "case #" << i << ": " << endl << cases[i] << endl;
	}
	return 0;
}

bool find_ignore(string word)
{
	bool ans{ false };
	for (auto& i : words_ignore) {
		if (word == i) {
			ans = true;
			break;
		}
	}
	return ans;
}