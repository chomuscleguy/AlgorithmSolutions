#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations)
{
	int arr[10001] = { 0 };

	for (int n : citations)
		arr[n]++;

	int total = 0;

	for (int i = 10000; i >= 0;i--)
	{
		total += arr[i];
		if (total >= i)
			return i;
	}

	return 0;
}

int main()
{
	int n;
	cin >> n;

	vector<int> citations(n);

	for (int i = 0;i < n;i++)
		cin >> citations[i];

	cout << solution(citations) << '\n';

	return 0;
}