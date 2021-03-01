#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 100 + 1
#define X first
#define Y second
using namespace std;

int n, m, x, y, a, b;
vector<pair<int, int>> board[MAX][MAX];
bool visited[MAX][MAX];
bool light[MAX][MAX];
bool check[MAX][MAX];

int pre = -1, now = 1;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    cin >> n >> m;
    while (m--) {
        cin >> x >> y >> a >> b;
        board[x][y].push_back({a, b});
    }

    queue<pair<int, int>> q;
    visited[1][1] = 1;
    q.push({1, 1});
    light[1][1] = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (auto nxt : board[cur.X][cur.Y]) light[nxt.X][nxt.Y] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            check[nx][ny] = 1;
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (light[i][j] && check[i][j] && !visited[i][j]) {
                    visited[i][j] = 1;
                    q.push({i, j});
                }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (light[i][j]) cnt++;

    std::cout << cnt << "\n";

    return 0;
}
