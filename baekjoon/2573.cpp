#include <iostream>
#include <queue>
#define MAX 305
using namespace std;

int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int board[MAX][MAX] = {0};
int time = 0;

void melt() {
    int tmp[MAX][MAX] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j])
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (board[nx][ny]) continue;
                    tmp[i][j]--;
                }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            board[i][j] += tmp[i][j];
            if (board[i][j] < 0) board[i][j] = 0;
        }

    return;
}

int count() {
    bool visited[MAX][MAX] = {0};
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] && !visited[i][j]) {
                cnt++;
                queue<pair<int, int>> q;
                visited[i][j] = 1;
                q.push({i, j});
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (!board[nx][ny] || visited[nx][ny]) continue;
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];

    while (1) {
        time++;
        melt();
        int cnt = count();
        if (!cnt) {
            cout << "0\n";
            break;
        } else if (cnt >= 2) {
            cout << time << "\n";
            break;
        }
    }
    return 0;
}
