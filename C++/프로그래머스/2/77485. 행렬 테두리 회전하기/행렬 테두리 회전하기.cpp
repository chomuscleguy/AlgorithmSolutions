#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;

	vector<vector<int>> grid(rows, vector<int>(columns));
	int num = 1;
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < columns; ++c) {
			grid[r][c] = num++;
		}
	}

	for (const vector<int>& v : queries) {
		int r1 = v[0] - 1, c1 = v[1] - 1;
		int r2 = v[2] - 1, c2 = v[3] - 1;

		int tmp = grid[r1][c1];
		int min_val = tmp;

		for (int r = r1; r < r2; r++) {
			grid[r][c1] = grid[r + 1][c1];
			min_val = min(min_val, grid[r][c1]);
		}

		for (int c = c1; c < c2; c++) {
			grid[r2][c] = grid[r2][c + 1];
			min_val = min(min_val, grid[r2][c]);
		}

		for (int r = r2; r > r1; r--) {
			grid[r][c2] = grid[r - 1][c2];
			min_val = min(min_val, grid[r][c2]);
		}

		for (int c = c2; c > c1 + 1; c--) {
			grid[r1][c] = grid[r1][c - 1];
			min_val = min(min_val, grid[r1][c]);
		}

		grid[r1][c1 + 1] = tmp;

		answer.push_back(min_val);
	}

	return answer;
}

int main() {
	int rows, cols;
	cin >> rows >> cols;

	int n, m;
	cin >> n >> m;

	vector<vector<int>> queries(n,vector<int>(m));
	
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> queries[i][j];
		
	for (int n : solution(rows, cols, queries))
		cout << n << ' ';

	cout << '\n';

	return 0;
}