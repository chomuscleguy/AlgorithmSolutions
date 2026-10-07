#include <iostream>

using namespace std;

int solution(int storey) {
	int answer = 0;

	while (storey) {
		int digit = storey % 10;
		int next_digit = (storey / 10) % 10;

		if (digit > 5) {
			answer += 10 - digit;
			storey += 10;
		}
		else if (digit == 5) {
			answer += 5;

			if (next_digit >= 5)
				storey += 10;
		}
		else
			answer += digit;

		storey /= 10;
	}

	return answer;
}

int main() {
	int storey;
	cin >> storey;

	cout << solution(storey) << '\n';

	return 0;
}