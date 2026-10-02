#include <iostream>
#include <string>
#include <vector>
#include <queue>	

using namespace std;

int dfs(int start, int n, const vector<vector<int>>& graph, int e1, int e2) {
	vector<bool> visited(n + 1, false);
	queue<int> q;

	q.push(start);
	visited[start] = true;
	int count = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		count++;

		for (int next : graph[cur]) {
			if ((cur == e1 && next == e2) || (cur == e2 && next == e1))
				continue;

			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	return count;
}

int solution(int n, vector<vector<int>> wires) {
	int answer = n;

	vector<vector<int>>graph(n + 1);

	for (const vector<int>& wire : wires) {
		graph[wire[0]].push_back(wire[1]);
		graph[wire[1]].push_back(wire[0]);
	}

	for (const vector<int>& wire : wires) {
		int v1 = wire[0];
		int v2 = wire[1];

		int count1 = dfs(v1, n, graph, v1, v2);
		int count2 = n - count1;

		int diff = abs(count1 - count2);
		answer = min(answer, diff);
	}


	return answer;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> wires(m, vector<int>(2));

	for (vector<int>& v : wires) {
		v.reserve(2);

		for (int i = 0; i < 2;i++)
			cin >> v[i];
	}

	cout << solution(n, wires) << '\n';

	return 0;
}