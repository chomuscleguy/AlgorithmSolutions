#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	int idx = 0;
	stack<int> sub_conveyor;

	for (int i = 0; i < order.size(); i++) {
		sub_conveyor.push(i + 1);

		while (!sub_conveyor.empty() && sub_conveyor.top() == order[idx]) {
			sub_conveyor.pop();
			idx++;
			answer++;
		}
	}

	return answer;
}

int main() {
	int n;
	cin >> n;

	vector<int> order(n);

	for (int i = 0; i < n; i++)
		cin >> order[i];

	cout << solution(order) << '\n';

	return 0;
}