#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
	int answer = 0;

	queue<pair<int, int>>q;
	for (int i = 0; i < priorities.size();i++)
		q.push({ i,priorities[i] });

	sort(priorities.rbegin(), priorities.rend());

	int order = 0;
	int idx = 0;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		if (cur.second == priorities[idx])
		{
			order++;

			if (cur.first == location)
				return order;

			idx++;
		}
		else
			q.push(cur);
	}

	return order;
}

int main()
{
	int n;
	cin >> n;

	vector<int> priorities(n);

	for (int i = 0; i < n; i++)
		cin >> priorities[i];

	int location;
	cin >> location;

	cout << solution(priorities, location) << '\n';

	return 0;
}