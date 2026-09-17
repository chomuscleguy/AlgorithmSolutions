#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string base(int n, int k) {
	if (n < k) return to_string(n);
	return base(n / k, k) + to_string(n % k);
}

bool isPrime(long long num) {
	if (num < 2)
		return false;

	for (long long i = 2; i * i <= num; i++)
		if (num % i == 0)
			return false;

	return true;
}

int solution(int n, int k) {
	int answer = 0;

	string num = base(n, k);

	stringstream ss(num);
	string token;

	while (getline(ss, token, '0')) {
		if (token.empty())
			continue;

		long long num = stoll(token);
		if (isPrime(num))
			answer++;
	}

	return answer;
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << solution(n, k) << '\n';

	return 0;
}