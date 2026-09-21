#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[1000001];

int solution(int x, int y, int n) {
	if (x == y)
		return 0;

	for (int i = x; i <= y; i++)
		visited[i] = -1;

	queue<int> q;

	q.push(x);
	visited[x] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int next_vals[3] = { cur + n, cur * 2, cur * 3 };

		for (int next : next_vals) {
			if (next == y)
				return visited[cur] + 1;

			if (next < y && visited[next] == -1) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}

	return -1;
}

int main() {
	int x, y, n;
	cin >> x >> y >> n;

	cout << solution(x, y, n) << '\n';

	return 0;
}