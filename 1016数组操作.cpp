#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

class arrays
{
public:
	int array_index;
	int value;	
};

bool compare(arrays a1, arrays a2);

int main()
{
	int N{0}, M{0};
	cin >> N >> M;
	vector<arrays> ans; 
	vector<int> indexs(N);
	int temp{0}, num{0};
	for (int i = 0; i < M; i++) {
		cin >> temp >> num;
		ans.push_back(arrays{temp, num});
		indexs[temp-1]++;
	}
	sort(ans.begin(), ans.end(), compare);
	int cnt{0}, sum{0};
	for (auto& i : indexs) {
		cout << i << " ";
		while (cnt < sum + i) {
			cout << ans[cnt++].value << " ";
		}
		sum += i;
		cout << endl;
	}
	return 0;
}

bool compare(arrays a1, arrays a2)
{
	if (a1.array_index != a2.array_index) {
		return a1.array_index < a2.array_index;
	}
	else {
		return a1.value < a2.value;
	}
}