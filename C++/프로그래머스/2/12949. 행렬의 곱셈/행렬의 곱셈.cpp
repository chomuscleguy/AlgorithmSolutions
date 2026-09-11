#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	int rows1 = arr1.size();
	int cols1 = arr1[0].size();
	int cols2 = arr2[0].size();

	vector<vector<int>> answer(rows1, vector<int>(cols2, 0));

	for (int i = 0; i < rows1; i++)
		for (int j = 0; j < cols2; j++)
			for (int k = 0; k < cols1; k++)
				answer[i][j] += arr1[i][k] * arr2[k][j];

	return answer;
}

int main()
{
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	vector<vector<int>> arr1(r1, vector<int>(c1));

	for (int i = 0; i < r1; i++)
		for (int j = 0; j < c1; j++)
			cin >> arr1[i][j];

	vector<vector<int>> arr2(r2, vector<int>(c2));

	for (int i = 0; i < r2; i++)
		for (int j = 0; j < c2; j++)
			cin >> arr2[i][j];

	vector<vector<int>> res = solution(arr1, arr2);

	for (vector<int> v : res)
	{
		for (int n : v)
			cout << n << ' ';
		cout << '\n';
	}

	return 0;
}