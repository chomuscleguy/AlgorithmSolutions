#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
	vector<int> answer;
	int n = maps.size();
	int m = maps[0].size();

	vector<vector<bool>> visited(n, vector<bool>(m, false));
	queue<pair<int, int>> q;

	pair<int, int> dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maps[i][j] != 'X' && !visited[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = true;

				int sum = 0;

				while (!q.empty()) {

					int r = q.front().first;
					int c = q.front().second;
					q.pop();

					sum += (maps[r][c] - '0');

					for (int i = 0; i < 4; i++) {
						int nr = r + dir[i].first;
						int nc = c + dir[i].second;

						if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
							if (maps[nr][nc] != 'X' && !visited[nr][nc]) {
								visited[nr][nc] = true;
								q.push({ nr,nc });
							}
						}
					}
				}
				answer.push_back(sum);
			}
		}
	}

	if (answer.empty())
		answer.push_back(-1);
	else
		sort(answer.begin(), answer.end());

	return answer;
}

int main() {
	int n;
	cin >> n;

	vector<string> maps(n);
	for (int i = 0; i < n; i++)
		cin >> maps[i];

	for (int n : solution(maps)) 
		cout << n << ' ';

	cout << '\n';

	return 0;
}