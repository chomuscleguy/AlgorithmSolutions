#include <iostream>
#include <string>

using namespace std;

int toSec(const string& a)
{
	int hour = (a[0] - '0') * 10 + (a[1] - '0');
	int min = (a[3] - '0') * 10 + (a[4] - '0');
	int sec = (a[6] - '0') * 10 + (a[7] - '0');

	return hour * 3600 + min * 60 + sec;
}

string twoDigit(int x)
{
	string s;
	s += char('0' + x / 10);
	s += char('0' + x % 10);
	return s;
}

void print(int a)
{
	if (a == 0)
	{
		cout << "24:00:00" << '\n';
		return;
	}

	int h = a / 3600;
	int m = (a % 3600) / 60;
	int s = a % 60;

	cout << twoDigit(h) << ':' << twoDigit(m) << ':' << twoDigit(s) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string A, B;
	cin >> A >> B;

	int diff = (toSec(B) - toSec(A) + 86400) % 86400;

	print(diff);

	return 0;
}