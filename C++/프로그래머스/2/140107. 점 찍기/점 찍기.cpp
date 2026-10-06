#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
	long long answer = 0;

	for (long long y = 0; y <= d; y += k) {
		long long max_x = sqrt(1LL * d * d - y * y);

		answer += (max_x / k) + 1;
	}

	return answer;
}

int main() {
	int k, d;
	cin >> k >> d;

	cout << solution(k, d) << '\n';

	return 0;
}