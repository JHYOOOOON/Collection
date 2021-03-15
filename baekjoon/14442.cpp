#include <cstring>
#include <iostream>
#include <queue>
#define MAX 1000 + 1
#define INF 10 + 1
using namespace std;

struct map {
    int x, y, cnt, dist;
};

int n, m, k;
char board[MAX][MAX];
int visited[MAX][MAX];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];

    memset(visited, INF, sizeof(visited));
    queue<map> q;
    visited[0][0] = 0;
    q.push({0, 0, 0, 1});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.x == n - 1 && cur.y == m - 1) {
            cout << cur.dist << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (board[nx][ny] == '1' && cur.cnt < k) {
                if (visited[nx][ny] <= cur.cnt + 1) continue;
                visited[nx][ny] = cur.cnt + 1;
                q.push({nx, ny, cur.cnt + 1, cur.dist + 1});
            } else if (board[nx][ny] == '0') {
                if (visited[nx][ny] <= cur.cnt) continue;
                visited[nx][ny] = cur.cnt;
                q.push({nx, ny, cur.cnt, cur.dist + 1});
            }
        }
    }

    cout << "-1\n";

    return 0;
}
