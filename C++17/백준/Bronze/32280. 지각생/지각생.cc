#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int toSec(const string& a)
{
	int hour = (a[0] - '0') * 10 + (a[1] - '0');
	int min = (a[3] - '0') * 10 + (a[4] - '0');
	return hour * 3600 + min * 60;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int teacherAttend = 0;
	vector<int> attend;

	for (int i = 0;i <= N;i++)
	{
		string hhmm, job;
		cin >> hhmm >> job;

		int sec = toSec(hhmm);

		if (job == "student")
			attend.push_back(sec);
		else
			teacherAttend = sec;
	}

	string hhmm;
	cin >> hhmm;

	int startTime = max(teacherAttend, toSec(hhmm));

	int ans = 0;

	for (int n : attend)
		if (n >= startTime)
			ans++;

	cout << ans << '\n';

	return 0;
}