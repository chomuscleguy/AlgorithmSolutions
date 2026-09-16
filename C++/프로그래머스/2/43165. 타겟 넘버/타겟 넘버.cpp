#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dfs(const vector<int>& numbers, int target, int idx, int sum) {
	if (idx == numbers.size())
		return (sum == target) ? 1 : 0;

	return dfs(numbers, target, idx + 1, sum + numbers[idx])
		+ dfs(numbers, target, idx + 1, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
	return dfs(numbers, target, 0, 0);
}

int main() {
	int n, target;
	cin >> n >> target;

	vector<int> numbers(n);

	for (int i = 0;i < n;i++)
		cin >> numbers[i];

	cout << solution(numbers, target) << '\n';

	return 0;
}