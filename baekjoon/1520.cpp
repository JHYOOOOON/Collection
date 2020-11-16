#include <iostream>
#define MAX 500 + 5
using namespace std;

int m, n;
int board[MAX][MAX] = {0};
int d[MAX][MAX] = {0};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int x, int y) {
    if (x == m - 1 && y == n - 1) return 1;

    if (d[x][y] == -1) {
        d[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                (board[nx][ny] < board[x][y])) {
                d[x][y] += dfs(nx, ny);
            }
        }
    }

    return d[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            d[i][j] = -1;
        }

    cout << dfs(0, 0) << "\n";
    return 0;
}
