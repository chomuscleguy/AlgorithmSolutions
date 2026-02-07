#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string S;
	cin >> S;

	int cnt = 0, res = 0;

	for (char c : S) 
	{
		if (isupper(c)) 
		{
			res += (4 - cnt % 4) % 4;
			cnt = 0;
		}
		cnt++;
	}

	cout << res;

	return 0;
}