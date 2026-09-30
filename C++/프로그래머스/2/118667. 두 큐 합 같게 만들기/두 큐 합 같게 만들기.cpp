#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
	int len = queue1.size();

	long long sum1 = 0;
	long long sum2 = 0;

	for (int n : queue1)
		sum1 += n;
	for (int n : queue2)
		sum2 += n;

	long long total_sum = sum1 + sum2;

	if (total_sum & 1)
		return -1;

	long long target = total_sum / 2;

	vector<int> combine = queue1;
	combine.insert(combine.end(), queue2.begin(), queue2.end());

	pair<int, int> p = { 0,len - 1 };

	int cnt = 0;

	while (p.first < combine.size() && p.second < combine.size()) {
		if (sum1 == target) {
			return cnt;
		}

		if (sum1 < target) {
			p.second++;
			if (p.second >= combine.size())
				break;
			sum1 += combine[p.second];
		}
		else {
			sum1 -= combine[p.first];
			p.first++;
		}

		cnt++;
	}

	return -1;
}

int main() {
	int n;
	cin >> n;

	vector<int> q1(n), q2(n);

	for (int i = 0; i < n;i++)
		cin >> q1[i];

	for (int i = 0; i < n;i++)
		cin >> q2[i];

	cout << solution(q1, q2) << '\n';

	return 0;
}