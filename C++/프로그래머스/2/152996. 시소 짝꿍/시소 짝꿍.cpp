#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
	long long answer = 0;

	map<int, long long> weight_count;
	for (int w : weights)
		weight_count[w]++;

	for (auto& pair : weight_count) {
		long long count = pair.second;
		if (count > 1)
			answer += (count * (count - 1)) / 2;
	}

	for (auto& pair : weight_count) {
		long long w = pair.first;
		long long count = pair.second;

		if ((w * 3) % 2 == 0) {
			int target = (w * 3) / 2;
			if (weight_count.count(target))
				answer += count * weight_count[target];
		}

		int target2 = w * 2;
		if (weight_count.count(target2))
			answer += count * weight_count[target2];

		if ((w * 4) % 3 == 0) {
			int target3 = (w * 4) / 3;
			if (weight_count.count(target3))
				answer += count * weight_count[target3];
		}
	}

	return answer;
}

int main() {
	int n;
	cin >> n;

	vector<int> weights(n);

	for (int i = 0; i < n; i++)
		cin >> weights[i];

	cout << solution(weights) << '\n';

	return 0;
}