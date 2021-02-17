#include <cstring>
#include <iostream>
#include <queue>
#define MAX 200 + 1
using namespace std;

int r, c, n;
char board[MAX][MAX];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> n;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> board[i][j];

    if (n % 2 == 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cout << 'O';
            cout << "\n";
        }
        return 0;
    }

    int time = 1;
    bool visited[MAX][MAX];
    while (time != n) {
        queue<pair<int, int>> q;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (board[i][j] == 'O') {
                    q.push({i, j});
                    visited[i][j] = 1;
                };

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = 1;
            }
        }

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                board[i][j] = (visited[i][j]) ? '.' : 'O';

        time += 2;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << board[i][j];
        cout << "\n";
    }

    return 0;
}
