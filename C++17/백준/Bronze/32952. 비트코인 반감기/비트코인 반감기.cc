#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long R, K, M;
	cin >> R >> K >> M;

	long long times = M / K;

	while (times-- && R)
		R >>= 1;

	cout << R << '\n';

	return 0;
}