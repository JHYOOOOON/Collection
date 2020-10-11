#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int n, k;
int S, X, Y;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    cin >> n >> k;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];

    cin >> S >> X >> Y;

    vector<vector<int>> visited(n, vector<int>(n, -1));
    queue<tuple<int, int, int>> q;  // x, y, time
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j]) {
                q.push({i, j, 0});
                visited[i][j] = 0;
            }

    int x, y, t;
    while (!q.empty()) {
        tie(x, y, t) = q.front();
        if (t == S) break;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny] == -1 ||
                (visited[nx][ny] == t + 1 && board[nx][ny] > board[x][y])) {
                visited[nx][ny] = t + 1;
                board[nx][ny] = board[x][y];
                q.push({nx, ny, t + 1});
            }
        }
    }

    cout << board[X - 1][Y - 1] << "\n";

    return 0;
}
