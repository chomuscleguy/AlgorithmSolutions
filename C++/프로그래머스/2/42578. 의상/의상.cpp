#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
	int answer = 1;

	unordered_map<string, int> um;

	for (int i = 0; i < clothes.size(); i++)
		um[clothes[i][1]]++;

	for (pair<string, int> p : um)
		answer *= (p.second + 1);

	return answer - 1;
}

int main()
{
	int n;
	cin >> n;

	vector<vector<string>> clothes(n, vector<string>(2));

	for (int i = 0; i < n; i++)
		cin >> clothes[i][0] >> clothes[i][1];

	cout << solution(clothes) << '\n';

	return 0;
}