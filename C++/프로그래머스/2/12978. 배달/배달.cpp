#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;

	vector<vector<pair<int, int>>> graph(N + 1);

	for (const auto& a : road) {
		graph[a[0]].push_back({ a[1],a[2] });
		graph[a[1]].push_back({ a[0],a[2] });
	}

	vector<int> dist(N + 1, 0x7FFFFFFF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[1] = 0;
	pq.push({ 0,1 });

	while (!pq.empty()) {
		int cur_dist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cur_dist > dist[cur])
			continue;

		for (const auto& a : graph[cur]) {
			int next = a.first;
			int weight = a.second;

			if (dist[cur] + weight < dist[next]) {
				dist[next] = dist[cur] + weight;
				pq.push({ dist[next],next });
			}
		}
	}

	for (int i = 1; i <= N; ++i)
		if (dist[i] <= K)
			answer++;

	return answer;
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<int>> road(M, vector<int>(3));

	for (vector<int>& v : road) 
		for (int i = 0; i < 3;i++)
			cin >> v[i];

	cout << solution(N, road, K) << '\n';

	return 0;
}