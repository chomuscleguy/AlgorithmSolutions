#include <iostream>
#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int from, int to, int temp, vector<vector<int>>& answer, int depth) {
    if (n == 1) {
        answer.push_back({ from, to });
        return;
    }

    hanoi(n - 1, from, temp, to, answer, depth + 1);

    answer.push_back({ from, to });

    hanoi(n - 1, temp, to, from, answer, depth + 1);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, 2, answer, 0);
    return answer;
}

int main() {
    int n;
    cin >> n;

    for (vector<int> v : solution(n)) {
        for (int n : v) 
            cout << n << ' ';
        cout << '\n';
    }

    return 0;
}