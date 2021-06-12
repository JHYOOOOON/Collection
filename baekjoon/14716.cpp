#include <iostream>
#include <queue>
#define MAX 250 + 5
using namespace std;

int m, n;
bool board[MAX][MAX], visited[MAX][MAX];

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

int main() {
    int ans = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] && !visited[i][j]) {
                visited[i][j] = 1;
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int k = 0; k < 8; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if (visited[nx][ny] || !board[nx][ny]) continue;
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }

    cout << ans << "\n";

    return 0;
}
