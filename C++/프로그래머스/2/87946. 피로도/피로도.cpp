#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_visited = 0;
vector<bool> visited;

void dfs(int cur, int count, const vector<vector<int>>& dungeons) {
	max_visited = max(max_visited, count);

	for (int i = 0; i < dungeons.size(); ++i) {
		int min = dungeons[i][0];
		int cost = dungeons[i][1];

		if (!visited[i] && cur >= min) {
			visited[i] = true;
			dfs(cur - cost, count + 1, dungeons);
			visited[i] = false;
		}
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	max_visited = 0;
	visited.assign(dungeons.size(), false);

	dfs(k, 0, dungeons);

	return max_visited;
}

int main() {
	int k, n;
	cin >> k >> n;

	vector<vector<int>> dungeons(n, vector<int>(2));

	for (int i = 0;i < n;i++)
		cin >> dungeons[i][0] >> dungeons[i][1];

	cout << solution(k, dungeons) << '\n';

	return 0;
}