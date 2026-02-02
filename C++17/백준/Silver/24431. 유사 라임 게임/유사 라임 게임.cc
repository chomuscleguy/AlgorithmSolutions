#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int n, L, F;
		cin >> n >> L >> F;

		unordered_map<string, int> um;
		um.reserve(n);

		string w;

		for (int i = 0;i < n;i++)
		{
			cin >> w;
			string suf = w.substr(L - F, F);
			um[suf]++;
		}

		int ans = 0;

		for (auto& p : um)
		{
			ans += p.second / 2;
		}

		cout << ans << "\n";
	}

	return 0;
}