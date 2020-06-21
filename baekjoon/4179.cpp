#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> board(r, vector<char>(c));
    vector<vector<int>> visited(r, vector<int>(c, -1));

    pair<int, int> start;
    queue<pair<int, int>> fire;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'J')
                start = {i, j};
            else if (board[i][j] == 'F') {
                fire.push({i, j});
                visited[i][j] = 0;
            }
        }
    }

    while (!fire.empty()) {
        auto cur = fire.front();
        fire.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (visited[nx][ny] != -1 || board[nx][ny] == '#') continue;

            visited[nx][ny] = visited[cur.first][cur.second] + 1;
            fire.push({nx, ny});
        }
    }

    vector<vector<bool>> visited2(r, vector<bool>(c));
    queue<tuple<int, int, int>> q;
    visited2[start.first][start.second] = 1;
    q.push({start.first, start.second, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << get<2>(cur) + 1 << "\n";
                return 0;
            }
            if (board[nx][ny] == '#' || visited2[nx][ny]) continue;
            if (visited[nx][ny] <= get<2>(cur) + 1 && visited[nx][ny] != -1)
                continue;

            visited2[nx][ny] = 1;
            q.push({nx, ny, get<2>(cur) + 1});
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
