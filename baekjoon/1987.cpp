#include <iostream>
using namespace std;

int r, c;
char board[25][25];
bool isused[30];
int mx = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, int cnt) {
    if (cnt > mx) mx = cnt;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (isused[board[nx][ny] - 'A']) continue;

        isused[board[nx][ny] - 'A'] = 1;
        dfs(nx, ny, cnt + 1);
        isused[board[nx][ny] - 'A'] = 0;
    }
    return;
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> board[i][j];

    isused[board[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << mx << "\n";

    return 0;
}
