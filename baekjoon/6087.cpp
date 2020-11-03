#include <iostream>
#include <queue>
#include <vector>
#define MAX 100 + 1
#define INF 10000
#define X first
#define Y second
using namespace std;

char board[MAX][MAX];
int visited[MAX][MAX];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int w, h;
pair<int, int> start = {-1, -1};
pair<int, int> arrive;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'C') {
                (start.X == -1 && start.Y == -1) ? start = {i, j}
                                                 : arrive = {i, j};
            }
        }

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) visited[i][j] = INF;

    queue<pair<pair<int, int>, pair<int, int>>> q;  // x, y, dir, mirror
    for (int i = 0; i < 4; i++) q.push({{start.X, start.Y}, {i, 0}});
    visited[start.X][start.Y] = 0;

    int x, y, dir, mirror;
    while (!q.empty()) {
        x = q.front().X.X;
        y = q.front().X.Y;
        dir = q.front().Y.X;
        mirror = q.front().Y.Y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nmirror = mirror;
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (board[nx][ny] == '*') continue;
            if (dir != i) nmirror++;
            if (visited[nx][ny] >= nmirror) {
                visited[nx][ny] = nmirror;
                q.push({{nx, ny}, {i, nmirror}});
            }
        }
    }

    cout << visited[arrive.X][arrive.Y] << "\n";
    return 0;
}
