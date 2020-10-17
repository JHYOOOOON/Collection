#include <iostream>
#include <vector>
#define MAX 500 + 1
using namespace std;

int n, m;
int board[MAX][MAX];
bool visited[MAX][MAX];
int mx = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void tetro(int a, int b, int cnt, int sum) {
    if (cnt == 4) {
        if (mx < sum) mx = sum;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = a + dx[i];
        int ny = b + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (visited[nx][ny]) continue;
        visited[nx][ny] = 1;
        tetro(nx, ny, cnt + 1, sum + board[nx][ny]);
        visited[nx][ny] = 0;
    }
}

void mino(int a, int b) {
    int sum = 0;
    if (a - 1 >= 0 && b - 1 >= 0 && a + 1 < n) {
        sum = board[a][b] + board[a - 1][b] + board[a][b - 1] + board[a + 1][b];
        if (mx < sum) mx = sum;
    }
    if (b - 1 >= 0 && a + 1 < n && b + 1 < m) {
        sum = board[a][b] + board[a][b - 1] + board[a + 1][b] + board[a][b + 1];
        if (mx < sum) mx = sum;
    }
    if (a + 1 < n && b + 1 < m && a - 1 >= 0) {
        sum = board[a][b] + board[a + 1][b] + board[a][b + 1] + board[a - 1][b];
        if (mx < sum) mx = sum;
    }
    if (b + 1 < m && a - 1 >= 0 && b - 1 >= 0) {
        sum = board[a][b] + board[a][b + 1] + board[a - 1][b] + board[a][b - 1];
        if (mx < sum) mx = sum;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 1;
            tetro(i, j, 1, board[i][j]);
            mino(i, j);
            visited[i][j] = 0;
        }
    }

    cout << mx << "\n";
    return 0;
}
