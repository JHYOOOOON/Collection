#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m, k, r, c;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    bool board[101][101] = {0}, visited[101][101] = {0};
    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;
        board[r][c] = 1;
    }

    int mx = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (board[i][j] && !visited[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;
                int cnt = 1;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                        if (!board[nx][ny] || visited[nx][ny]) continue;
                        cnt++;
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                if (mx < cnt) mx = cnt;
            }
        }

    cout << mx << "\n";

    return 0;
}
