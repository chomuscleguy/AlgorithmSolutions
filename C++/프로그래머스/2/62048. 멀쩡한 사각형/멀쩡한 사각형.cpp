#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long long solution(int w, int h) {
	return 1LL * w * h - (w + h - gcd(w, h));
}

int main() {
	int w, h;
	cin >> w >> h;

	cout << solution(w, h) << '\n';

	return 0;
}