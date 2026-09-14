#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
	int answer = 0;
	unordered_map<string, int>umWant;

	for (int i = 0; i < want.size(); i++)
		umWant[want[i]] = number[i];

	unordered_map<string, int> umDiscount;

	for (int i = 0; i < 10; i++)
		umDiscount[discount[i]]++;

	if (umWant == umDiscount)
		answer++;

	for (int i = 10; i < discount.size(); i++)
	{
		string outItem = discount[i - 10];

		umDiscount[outItem]--;
		if (umDiscount[outItem] == 0) 
		{
			umDiscount.erase(outItem);
		}

		umDiscount[discount[i]]++;

		if (umWant == umDiscount)
			answer++;
	}

	return answer;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<string> want(n);
	vector<int> number(n);
	vector<string> discount(m);

	for (int i = 0;i < n;i++)
		cin >> want[i];

	for (int i = 0;i < n;i++)
		cin >> number[i];

	for (int i = 0;i < m;i++)
		cin >> discount[i];

	cout << solution(want, number, discount) << '\n';

	return 0;
}