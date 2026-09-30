#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	int len = sequence.size();

	pair<int, int> min_pos = { 0,0 };
	int min_cnt = 0x7FFFFFFF;

	pair<int, int> cur_pos = { 0,0 };
	int sum = sequence[0];

	while (cur_pos.first <= cur_pos.second && cur_pos.second < len) {
		if (sum == k) {
			int cur_cnt = cur_pos.second - cur_pos.first + 1;

			if (cur_cnt < min_cnt) {
				min_cnt = cur_cnt;
				min_pos = cur_pos;
			}
			sum -= sequence[cur_pos.first++];
		}
		else if (sum < k) {
			cur_pos.second++;

			if (cur_pos.second < len)
				sum += sequence[cur_pos.second];
		}
		else
			sum -= sequence[cur_pos.first++];
	}

	return { min_pos.first,min_pos.second };
}

int main() {
	int n;
	cin >> n;

	vector<int> sequence(n);

	int k;
	cin >> k;

	for (int i = 0; i < n; i++)
		cin >> sequence[i];

	for (int n : solution(sequence, k))
		cout << n << ' ';
	cout << '\n';

	return 0;
}