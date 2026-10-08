#include <iostream>
#include <string>
#include <vector>

#define SIZE 5

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool dfs(const vector<string>& place, vector<vector<bool>>& visited, int x, int y, int dist) {
	if (dist > 2)
		return true;

	if (dist > 0 && place[x][y] == 'P')
		return false;

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE)
			if (!visited[nx][ny] && place[nx][ny] != 'X')
				if (!dfs(place, visited, nx, ny, dist + 1))
					return false;
	}

	return true;
}

bool checkPlace(const vector<string>& place) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (place[i][j] == 'P') {
				vector<vector<bool>> visited(SIZE, vector<bool>(SIZE, false));
				if (!dfs(place, visited, i, j, 0))
					return false;
			}

	return true;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (const auto& place : places)
		if (checkPlace(place))
			answer.push_back(1);
		else
			answer.push_back(0);

	return answer;
}

int main() {
	vector<vector<string>> places(SIZE, vector<string>(SIZE));

	for (int i = 0;i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			cin >> places[i][j];

	for (const int& n : solution(places))
		cout << n << ' ';

	cout << '\n';

	return 0;
}