#include <iostream>
#define MAX 500 + 5
#define X first
#define Y second
using namespace std;

int n;
int board[MAX][MAX];
int d[MAX][MAX] = {0};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int panda(int x, int y) {
    if (d[x][y]) return d[x][y];

    d[x][y] = 1;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (board[nx][ny] <= board[x][y]) continue;

        d[x][y] = max(d[x][y], panda(nx, ny) + 1);
    }

    return d[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];

    int k = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) k = max(k, panda(i, j));

    cout << k << "\n";
    return 0;
}
