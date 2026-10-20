#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int size = cards.size();
    vector<bool> visited(size, false);
    vector<int> group_sizes;

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            int current = i;
            int size = 0;

            while (!visited[current]) {
                visited[current] = true;
                current = cards[current] - 1;
                size++;
            }
            group_sizes.push_back(size);
        }
    }

    if (group_sizes.size() < 2) 
        return 0;

    sort(group_sizes.rbegin(), group_sizes.rend());

    return group_sizes[0] * group_sizes[1];
}

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);

    for (int i = 0; i < n; i++)
        cin >> cards[i];

    cout << solution(cards) << '\n';
    
    return 0;
}