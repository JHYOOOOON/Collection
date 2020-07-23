#include <iostream>
#include <queue>
#define MAX 55
#define X first
#define Y second
using namespace std;

int r, c;
char board[MAX][MAX];
int mx = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void BFS(int x, int y) {
    int dist[MAX][MAX];
    for (int i = 0; i < r; i++) fill(dist[i], dist[i] + c, -1);

    queue<pair<int, int>> q;
    dist[x][y] = 0;
    q.push({x, y});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] == 'W') continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
            mx = max(mx, dist[nx][ny]);
        }
    }
    return;
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> board[i][j];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (board[i][j] == 'L') BFS(i, j);

    cout << mx << "\n";
    return 0;
}
