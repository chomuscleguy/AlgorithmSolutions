#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string word) {
	int answer = 0;
	int weight[5] = { 781,156,31,6,1 };
	string vowels = "AEIOU";

	for (int i = 0; i < word.size();i++) {
		int idx = vowels.find(word[i]);
		answer += idx * weight[i] + 1;
	}

	return answer;
}


int main() {
	string word;
	cin >> word;

	cout << solution(word) << '\n';

	return 0;
}