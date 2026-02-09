#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt[9] = {};

	string N;
	cin >> N;

	for (char c : N)
	{
		int d = c - '0';
		if (d == 9)
			d = 6;
		cnt[d]++;
	}

	cnt[6] = (cnt[6] + 1) / 2;

	int res = 0;

	for (int i = 0;i < 9; i++)
		res = max(res, cnt[i]);

	cout << res << '\n';

	return 0;
}