#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 50 + 1
using namespace std;

int n, m, mx = 0;
int board[MAX][MAX];
queue<pair<int, int>> q;

int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!board[nx][ny]) {
                q.push({nx, ny});
                board[nx][ny] = board[x][y] + 1;
                mx = max(mx, board[nx][ny]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j]) q.push({i, j});
        }

    bfs();

    cout << mx - 1 << "\n";

    return 0;
}
