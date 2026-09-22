#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;
	answer.reserve(numbers.size());

	for (long long x : numbers) {
		if (x & 1) {
			long long lowest_zero = (~x) & (x + 1);
			
			long long next_num = x + lowest_zero - (lowest_zero >> 1);
			answer.push_back(next_num);
		}
		else
			answer.push_back(x + 1);
	}

	return answer;
}

int main() {
	int n;
	cin >> n;

	vector<long long> v(n);

	for (int i = 0;i < n;i++)
		cin >> v[i];

	for (long long n : solution(v))
		cout << n << ' ';

	cout << '\n';

	return 0;
}