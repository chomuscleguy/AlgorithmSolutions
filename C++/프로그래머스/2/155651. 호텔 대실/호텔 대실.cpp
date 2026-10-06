#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto to_min = [](const string& s) -> int { return  ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + (s[4] - '0'); };

int solution(vector<vector<string>> book_time) {
	vector<pair<int, int>> v;

	vector<int> time_line(1460, 0);

	for (const auto& book : book_time) {
		int start = to_min(book[0]);
		int end = to_min(book[1]) + 10;

		time_line[start] += 1;
		time_line[end] -= 1;
	}

	int max_rooms = 0;
	int current_rooms = 0;

	for (int t = 0; t < 1460; ++t) {
		current_rooms += time_line[t];
		max_rooms = max(max_rooms, current_rooms);
	}

	return max_rooms;
}

int main() {
	int N;
	cin >> N;

	vector<vector<string>> book_time(N, vector<string>(2));

	for (int i = 0; i < N; i++) 
		cin >> book_time[i][0] >> book_time[i][1];

	cout << solution(book_time) << '\n';

	return 0;
}