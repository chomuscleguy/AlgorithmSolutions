#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int cur_weight = 0;
	int idx = 0;
	queue<int> q;

	for (int i = 0; i < bridge_length; i++)
		q.push(0);

	while (!q.empty()) {
		answer++;

		cur_weight -= q.front();
		q.pop();

		if (idx < truck_weights.size()) {
			if (cur_weight + truck_weights[idx] <= weight) {
				q.push(truck_weights[idx]);
				cur_weight += truck_weights[idx];
				idx++;
			}
			else
				q.push(0);
		}
	}

	return answer;
}

int main() {
	int n;
	cin >> n;
	vector<int> truck_weight(n);

	for (int i = 0;i < n;i++)
		cin >> truck_weight[i];

	int brigde_length, weight;
	cin >> brigde_length >> weight;

	cout << solution(brigde_length, weight, truck_weight) << '\n';

	return 0;
}