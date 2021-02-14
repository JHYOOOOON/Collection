#include <algorithm>
#include <cstring>
#include <iostream>
#define MAX 50 + 1
#define X first
#define Y second
using namespace std;

int n, m;
bool flag;
pair<int, int> start;
char board[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int cnt, char color) {
    if (flag) return;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (visited[nx][ny]) {
            if (cnt >= 4 && start.X == nx && start.Y == ny) {
                flag = 1;
                return;
            }
        } else {
            if (board[nx][ny] == color) {
                visited[nx][ny] = 1;
                dfs(nx, ny, cnt + 1, color);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            memset(visited, false, sizeof(visited));
            start = {i, j};
            visited[i][j] = 1;
            dfs(i, j, 1, board[i][j]);
            if (flag) {
                cout << "Yes\n";
                return 0;
            }
        }

    cout << "No\n";
    return 0;
}
