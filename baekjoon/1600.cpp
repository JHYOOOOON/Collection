#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int k, w, h;
int board[200][200];
bool visited[200][200][30];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int horse_x[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int horse_y[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    cin >> k >> h >> w;
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++) cin >> board[i][j];

    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {0, 0}});
    visited[0][0][0] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.first.first == w - 1 && cur.first.second == h - 1) {
            cout << cur.second.second << "\n";
            return 0;
        }
        if (cur.second.first < k) {
            for (int i = 0; i < 8; i++) {
                int nx = cur.first.first + horse_x[i];
                int ny = cur.first.second + horse_y[i];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if (visited[nx][ny][cur.second.first + 1] || board[nx][ny])
                    continue;
                visited[nx][ny][cur.second.first + 1] = 1;
                q.push(
                    {{nx, ny}, {cur.second.first + 1, cur.second.second + 1}});
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.first.first + dx[i];
            int ny = cur.first.second + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (visited[nx][ny][cur.second.first] || board[nx][ny]) continue;
            visited[nx][ny][cur.second.first] = 1;
            q.push({{nx, ny}, {cur.second.first, cur.second.second + 1}});
        }
    }

    cout << -1 << "\n";

    return 0;
}
