#include <iostream>
#include <algorithm>

using namespace std;

int toMinute(const string& t)
{
	int hour = (t[0] - '0') * 10 + (t[1] - '0');
	int min = (t[3] - '0') * 10 + (t[4] - '0');

	return hour * 60 + min;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string t1, t2;
	cin >> t1 >> t2;

	int a = toMinute(t1);
	int b = toMinute(t2);

	int diff = abs(a - b);
	diff = min(diff, 720 - diff);

	cout << diff * 6 << '\n';

	return 0;
}