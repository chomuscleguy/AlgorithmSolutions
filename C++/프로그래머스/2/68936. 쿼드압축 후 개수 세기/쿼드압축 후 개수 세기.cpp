#include <iostream>
#include <string>
#include <vector>

using namespace std;

void compress(int x, int y, int size, const vector<vector<int>>& arr, vector<int>& answer) {
	int first_val = arr[x][y];
	bool is_same = true;

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (first_val != arr[i][j]) {
				is_same = false;
				break;
			}
		}
		if (!is_same)
			break;
	}

	if (is_same) {
		answer[first_val]++;
		return;
	}

	int half = size / 2;
	compress(x, y, half, arr, answer);
	compress(x, y + half, half, arr, answer);
	compress(x + half, y, half, arr, answer);
	compress(x + half, y + half, half, arr, answer);
}

vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer(2, 0);
	compress(0, 0, arr.size(), arr, answer);

	return answer;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(n));

	for (vector<int> &v : arr)
		for (int i = 0;i < n;i++)
			cin >> v[i];

	for (int n : solution(arr))
		cout << n << ' ';
	cout << '\n';

	return 0;
}