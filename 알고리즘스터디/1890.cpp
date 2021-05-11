#include <iostream>
#define MAX 100 + 5
using namespace std;

int n;
int board[MAX][MAX];
long long d[MAX][MAX];

long long dfs(int x, int y) {
    if (x == n - 1 && y == n - 1) return 1;

    if (d[x][y] == -1) {
        d[x][y] = 0;

        int rx = x + board[x][y];
        int ry = y;
        if (rx >= 0 && rx < n && ry >= 0 && ry < n) d[x][y] += dfs(rx, ry);

        int dx = x;
        int dy = y + board[x][y];
        if (dx >= 0 && dx < n && dy >= 0 && dy < n) d[x][y] += dfs(dx, dy);
    }

    return d[x][y];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            d[i][j] = -1;
        }

    cout << dfs(0, 0) << "\n";
    return 0;
}
