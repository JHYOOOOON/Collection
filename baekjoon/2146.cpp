#include <cstring>
#include <iostream>
#include <queue>
#define MAX 100 + 1
#define INF 10000
#define X first
#define Y second
using namespace std;

int n, x, y, color = 2;
int visited[MAX][MAX], board[MAX][MAX];
int mn = INF;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void check(int color) {
    memset(visited, -1, sizeof(visited));

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == color) {
                visited[i][j] = 0;
                q.push({i, j});
            }

    while (!q.empty()) {
        x = q.front().X;
        y = q.front().Y;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny] >= 0) continue;

            if (board[nx][ny] != color && board[nx][ny]) {
                mn = min(mn, visited[x][y]);
            } else {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void init() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == 1) {
                queue<pair<int, int>> q;
                board[i][j] = color;
                q.push({i, j});
                while (!q.empty()) {
                    x = q.front().X;
                    y = q.front().Y;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] == 0 || board[nx][ny] == color)
                            continue;

                        board[nx][ny] = color;
                        q.push({nx, ny});
                    }
                }

                color++;
            }
    return;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    init();
    for (int i = 2; i < color; i++) check(i);

    cout << mn << "\n";

    return 0;
}
