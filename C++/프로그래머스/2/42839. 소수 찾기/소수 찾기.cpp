#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

unordered_set<int> us;
bool visited[10];

bool isPrime(int num) {
    if (num < 2)
        return false;

    for (int i = 2; i <= sqrt(num); i++) 
        if (num % i == 0) 
            return false;

    return true;
}

void dfs(string numbers, string cur) {
    if (!cur.empty())
        us.insert(stoi(cur));

    for (int i = 0; i < numbers.size(); i++) {
        if (visited[i])
            continue;

        visited[i] = true;                    
        dfs(numbers, cur + numbers[i]);
        visited[i] = false;                   
    }
}

int solution(string numbers) {
    dfs(numbers, "");

    int answer = 0;
    for (int num : us) {
        if (isPrime(num)) {
            answer++;
        }
    }

    return answer;
}

int main() {
	string numbers;
	cin >> numbers;

	cout << solution(numbers) << '\n';

	return 0;
}