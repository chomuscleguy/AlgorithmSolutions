#include <iostream>

using namespace std;

int ElixirofGiantGrowth(int level)
{
	if (level < 206)
		return 1;
	if (level < 218)
		return 2;
	if (level < 229)
		return 3;
	return 4;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	cout << ElixirofGiantGrowth(N) << '\n';

	return 0;
}