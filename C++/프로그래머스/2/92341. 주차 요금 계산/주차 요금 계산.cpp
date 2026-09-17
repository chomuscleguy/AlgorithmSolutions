#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int toMin(const string& time) {
	int hour = (time[0] - '0') * 10 + (time[1] - '0');
	int min = (time[3] - '0') * 10 + (time[4] - '0');
	return hour * 60 + min;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	map<string, int> inTime;
	map<string, int> totalTime;

	for (const string& record : records) {
		stringstream ss(record);
		string timeStr, numer, type;
		ss >> timeStr >> numer >> type;

		int time = toMin(timeStr);

		if (type == "IN")
			inTime[numer] = time;
		else {
			totalTime[numer] += (time - inTime[numer]);
			inTime.erase(numer);
		}
	}

	int lastTime = toMin("23:59");

	for (pair<string, int> p : inTime)
		totalTime[p.first] += (lastTime - p.second);

	vector<int> answer;
	for (pair<string, int> p : totalTime) {
		int fee = fees[1];

		if (p.second > fees[0]) {
			int extraTime = p.second - fees[0];
			int unitCount = (extraTime + fees[2] - 1) / fees[2];
			fee += unitCount * fees[3];
		}

		answer.push_back(fee);
	}

	return answer;
}

int main() {
	vector<int> fees(4);

	for (int i = 0; i < 4; i++)
		cin >> fees[i];

	int n;
	cin >> n;
	cin.ignore();

	vector<string> records(n);

	for (int i = 0;i < n; i++)
		getline(cin, records[i]);

	for (int n : solution(fees, records))
		cout << n << ' ';
	cout << '\n';

	return 0;
}