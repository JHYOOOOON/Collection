#include <iostream>
#include <queue>
#include <tuple>
#define MAX 100 + 1

using namespace std;
using tiii = tuple<int, int, int>;

char board[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int breakWall(int a, int b) {
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    pq.push({0, a, b});
    visited[a][b] = 1;

    int x, y, cnt;
    while (!pq.empty()) {
        tie(cnt, x, y) = pq.top();
        pq.pop();

        if (x == n - 1 && y == m - 1) return cnt;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = 1;
            (board[nx][ny] == '0') ? pq.push({cnt, nx, ny})
                                   : pq.push({cnt + 1, nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];

    cout << breakWall(0, 0) << "\n";
    return 0;
}
