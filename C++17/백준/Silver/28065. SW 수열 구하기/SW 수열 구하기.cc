#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i <= N / 2; i++)
		cout << N + 1 - i << ' ' << i << ' ';

	if (N & 1)
		cout << (N + 1) / 2;

	return 0;
}