#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
	int len = numbers.size();
	vector<int> answer(len, -1);
	stack<int> st;

	for (int i = 0; i < len; i++) {
		while (!st.empty() && numbers[st.top()] < numbers[i]) {
			answer[st.top()] = numbers[i];
			st.pop();
		}
		st.push(i);
	}

	return answer;
}

int main() {
	int n;
	cin >> n;

	vector<int> numbers(n);

	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	return 0;
}