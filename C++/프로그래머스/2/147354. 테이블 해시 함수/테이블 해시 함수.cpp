#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
	int target_col = col - 1;

	sort(data.begin(), data.end(), [target_col](const vector<int>& a, const vector<int>& b) {
		if (a[target_col] == b[target_col])
			return a[0] > b[0];

		return a[target_col] < b[target_col];
		});

	int answer = 0;
	bool first_xor = true;

	for (int i = row_begin - 1; i < row_end;i++) {
		int s_i = 0;
		int row_index = i + 1;

		for (int n : data[i])
			s_i += n % row_index;

		if (first_xor) {
			answer = s_i;
			first_xor = false;
		}
		else
			answer ^= s_i;
	}

	return answer;
}

int main() {
	int n;
	cin >> n;

	vector < vector<int>> data(n, vector<int>(3));

	for (int i = 0; i < n; i++)
		cin >> data[i][0] >> data[i][1] >> data[i][2];

	int col, row_begin, row_end;
	cin >> col >> row_begin >> row_end;

	cout << solution(data, col, row_begin, row_end) << '\n';

	return 0;
}