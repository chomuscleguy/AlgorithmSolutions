#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	vector<vector<int>> triangle(n, vector<int>(n, 0));

	pair <int, int> dir[3] = { {1,0} ,{0,1},{-1,-1} };

	int x = -1, y = 0;
	int num = 1;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			pair<int, int> cur = dir[i % 3];
			x += cur.first;
			y += cur.second;

			triangle[x][y] = num++;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			answer.push_back(triangle[i][j]);

	return answer;
}

int main() {
	int n;
	cin >> n;

	for (int m : solution(n))
		cout << m << ' ';

	cout << '\n';

	return 0;
}