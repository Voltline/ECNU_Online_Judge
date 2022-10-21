#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Alphabet
{
public:
	char c_upper;
	char c_lower;
	double frequency;	
};

vector<Alphabet> alphabet;

bool compare(char c1, char c2);

int main()
{
	for (int i = 0; i < 26; i++) {
		alphabet.push_back(Alphabet{static_cast<char>('A'+i), static_cast<char>('a'+i), 0});
	}

	int T{0};
	cin >> T;
	string line;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 26; j++) {
			cin >> alphabet[j].frequency;
		}
		getline(cin, line);
		getline(cin, line);
		sort(line.begin(), line.end(), compare);
		cout << "case #" << i << ":" << endl << line << endl;
	}
	return 0;
}

bool compare(char c1, char c2)
{
	char c1_inner = tolower(c1), c2_inner = tolower(c2);
	
	if (c1_inner != c2_inner) {
		if (fabs(alphabet[c1_inner-97].frequency - alphabet[c2_inner-97].frequency) > 1e-5)
			return alphabet[c1_inner-97].frequency > alphabet[c2_inner-97].frequency;
		else return c1_inner < c2_inner;
	}
	else {
		return c1 > c2;
	}
}