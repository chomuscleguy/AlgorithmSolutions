#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	vector<string> strNums;
	for (int num : numbers)
		strNums.push_back(to_string(num));

	sort(strNums.begin(), strNums.end(), compare);

	string answer = "";

	if (strNums[0] == "0")
		return "0";

	for (const string& s : strNums)
		answer += s;

	return answer;
}

int main() {
	int n;
	cin >> n;

	vector<int> numbers(n);

	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	cout << solution(numbers) << '\n';

	return 0;
}