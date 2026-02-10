#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int arr[51] = {};

	while (N--)
	{
		int i;
		cin >> i;

		arr[i]++;
	}

	int res = -1;

	for (int i = 0; i < 51;i++)
		if (arr[i] == i)
			res = max(i, res);

	cout << res << '\n';

	return 0;
}