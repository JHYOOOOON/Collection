#include <iostream>
#include <queue>
#define MAX 100 + 1
#define X first
#define Y second
using namespace std;

int n, m;
int board[MAX][MAX];
bool visited[MAX][MAX];
int cheese = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isClear() {
    bool flag = true;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (board[i][j]) {
                cnt++;
                flag = false;
            }
        }

    if (!flag) cheese = cnt;
    return flag;
}

void reset() {
    for (int i = 0; i < n; i++) fill(visited[i], visited[i] + m, 0);
    return;
}

void melt() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 2) board[i][j] = 0;
    return;
}

void edge() {
    reset();
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({0, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny])
                board[nx][ny] = 2;
            else {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];

    for (int time = 0;; time++) {
        if (isClear()) {
            cout << time << "\n" << cheese << "\n";
            return 0;
        }
        edge();
        melt();
    }
    return 0;
}
