#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Point
{
public:
	unsigned int loc_x;
	unsigned int loc_y;
	Point()
	{
		this->loc_x = -1;
		this->loc_y = -1;
	}
	Point(int x, int y)
	{
		this->loc_x = x;
		this->loc_y = y;
	}
	bool operator==(Point p2)
	{
		if (this->loc_x == p2.loc_x && this->loc_y == p2.loc_y) {
			return true;
		}
		else {
			return false;
		}
	}
	friend ostream& operator<<(ostream& output, Point p1)
	{
		output << p1.loc_x << " " << p1.loc_y;
		return output;
	}
};

vector<Point> find_max_in_row(int matrix[5][5], int row_index);
vector<Point> find_min_in_column(int matrix[5][5], int column_index);

int main()
{
	int T{ 0 };
	cin >> T;
	vector<Point> ans;
	vector<Point> max_in_row;
	vector<Point> temp_row;
	vector<Point> min_in_column;
	vector<Point> temp_column;
	int matrix[5][5]{ 0 };
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> matrix[j][k];
			}
		}
		for (int j = 0; j < 5; j++) {
			temp_row = find_max_in_row(matrix, j);
			for (auto& k : temp_row) {
				max_in_row.push_back(k);
			}
		}
		for (int j = 0; j < 5; j++) {
			temp_column = find_min_in_column(matrix, j);
			for (auto& k : temp_column) {
				min_in_column.push_back(k);
			}
		}
		int cnt{ 0 };
		for (auto& j : max_in_row) {
			for (auto& k : min_in_column) {
				if (j == k) {
					ans.push_back(j);
					cnt++;
				}
			}
		}
		cout << "case #" << i << ":" << endl;
		if (cnt != 0) {
			for (auto& j : ans) {
				cout << j << endl;
			}
		}
		else {
			cout << "-1 -1" << endl;
		}
		vector<Point>().swap(ans);
		vector<Point>().swap(min_in_column);
		vector<Point>().swap(max_in_row);
	}
	return 0;
}

vector<Point> find_max_in_row(int matrix[5][5], int row_index)
{
	vector<Point> points;
	int maximum = 0;
	for (int i = 0; i < 5; i++) {
		if (matrix[row_index][i] > maximum) {
			maximum = matrix[row_index][i];
		}
	}
	for (int i = 0; i < 5; i++) {
		if (matrix[row_index][i] == maximum) {
			points.push_back(Point{ row_index, i });
		}
	}
	return points;
}

vector<Point> find_min_in_column(int matrix[5][5], int column_index)
{
	vector<Point> points;
	int minimum = 101;
	for (int i = 0; i < 5; i++) {
		if (matrix[i][column_index] < minimum) {
			minimum = matrix[i][column_index];
		}
	}
	for (int i = 0; i < 5; i++) {
		if (matrix[i][column_index] == minimum) {
			points.push_back(Point{ i, column_index });
		}
	}
	return points;
}
