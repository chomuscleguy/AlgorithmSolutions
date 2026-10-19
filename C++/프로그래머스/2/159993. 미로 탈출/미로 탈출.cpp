#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(char start_char, char target_char, const vector<string>& maps) {
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>> q;

    int sr = -1, sc = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maps[i][j] == start_char) {
                sr = i;
                sc = j;
                break;
            }
        }
        if (sr != -1) break;
    }

    q.push({ {sr, sc}, 0 });
    visited[sr][sc] = true;

    int dr[] = { -1, 1, 0, 0 };
    int dc[] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        auto [curr, dist] = q.front();
        int r = curr.first;
        int c = curr.second;
        q.pop();

        if (maps[r][c] == target_char) {
            return dist;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (!visited[nr][nc] && maps[nr][nc] != 'X') {
                    visited[nr][nc] = true;
                    q.push({ {nr, nc}, dist + 1 });
                }
            }
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    int to_lever = bfs('S', 'L', maps);

    if (to_lever == -1) 
        return -1;

    int to_exit = bfs('L', 'E', maps);

    if (to_exit == -1) 
        return -1;

    return to_lever + to_exit;
}

int main() {
    int n;
    cin >> n;

    vector<string> maps(n);

    for (int i = 0; i < n;i++)
        cin >> maps[i];

    cout << solution(maps) << '\n';

    return 0;
}