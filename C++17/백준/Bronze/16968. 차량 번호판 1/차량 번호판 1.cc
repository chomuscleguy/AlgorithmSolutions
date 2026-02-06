#include <iostream>

using namespace std;

int calc(char c)
{
	if (c == 'd')
		return 10;

	if (c == 'c')
		return 26;

	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string form;
	cin >> form;

	int cnt = form.size();
	int res = calc(form[0]);

	for (int i = 1; i < cnt;i++)
	{
		int n = calc(form[i]);

		if (form[i] == form[i - 1])
			n--;

		res *= n;
	}

	cout << res << '\n';
	return 0;
}