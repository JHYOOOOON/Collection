#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 10
using namespace std;

int n, m;
int board[MAX][MAX];
int wall_board[MAX][MAX];
int mx = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void BFS() {
    int temp[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) temp[i][j] = wall_board[i][j];

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (temp[i][j] == 2) q.push({i, j});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (temp[nx][ny] == 0) {
                temp[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (temp[i][j] == 0) cnt++;

    mx = max(mx, cnt);
}

void wall(int cnt) {
    if (cnt == 3) {
        BFS();
        return;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (wall_board[i][j] == 0) {
                wall_board[i][j] = 1;
                wall(cnt + 1);
                wall_board[i][j] = 0;
            }
}

void copy_board() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) wall_board[i][j] = board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (wall_board[i][j] == 0) {
                wall_board[i][j] = 1;
                wall(1);
                wall_board[i][j] = 0;
            }

    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];

    copy_board();

    cout << mx << "\n";
    return 0;
}
