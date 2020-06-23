#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    int n, m;
    cin >> n >> m;

    pair<int, int> start;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == '2') start = {i, j};
        }

    vector<vector<int>> dist(n, vector<int>(m));
    for (int i = 0; i < n; i++) fill(dist[i].begin(), dist[i].end(), -1);
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.X][start.Y] = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != -1 || board[nx][ny] == '1') continue;
            if (board[nx][ny] >= '3') {
                ::cout << "TAK\n" << dist[cur.X][cur.Y] + 1 << "\n";
                return 0;
            } else {
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }
    }
    ::cout << "NIE\n";
    return 0;
}
