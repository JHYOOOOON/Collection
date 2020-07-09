#include <iostream>
#include <queue>
#include <tuple>
#define MAX 1005
using namespace std;

int n, m;
char board[MAX][MAX];
int dist[MAX][MAX][2];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs() {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int w = get<2>(q.front());
        q.pop();

        if (x == n - 1 && y == m - 1) return dist[x][y][w];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny][w]) continue;
            if (board[nx][ny] == '0') {
                dist[nx][ny][w] = dist[x][y][w] + 1;
                q.push({nx, ny, w});
            }
            if (board[nx][ny] == '1' && w == 0) {
                dist[nx][ny][1] = dist[x][y][w] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];
    cout << bfs();
    return 0;
}
