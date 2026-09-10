#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> elements)
{
	bool visited[1000001] = { false };
	int n = elements.size();

	vector<int> extended = elements;
	extended.insert(extended.end(), elements.begin(), elements.end());

	int count = 0;

	for (int len = 1; len <= n; len++)
	{
		int window = 0;

		for (int i = 0; i < len; i++)
			window += extended[i];

		if (!visited[window])
		{
			visited[window] = true;
			count++;
		}

		for (int start = 1; start < n; start++)
		{
			window += extended[start + len - 1] - extended[start - 1];

			if (!visited[window])
			{
				visited[window] = true;
				count++;
			}
		}
	}

	return count;
}

int main()
{
	int n;
	cin >> n;

	vector<int> element(n);

	for (int i = 0;i < n;i++)
		cin >> element[i];

	cout << solution(element) << '\n';

	return 0;
}