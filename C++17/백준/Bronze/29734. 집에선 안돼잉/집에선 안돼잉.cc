#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N, M;
	int T, S;
	cin >> N >> M >> T >> S;

	long long zip = N + ((N + 7) / 8 - 1) * S;
	long long dok = M + ((M + 7) / 8 - 1) * (2 * T + S) + T;

	if (zip < dok)
	{
		cout << "Zip" << '\n';
		cout << zip << '\n';
	}
	else
	{
		cout << "Dok" << '\n';
		cout << dok << '\n';
	}

	return 0;
}