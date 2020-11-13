#include <iostream>
#include <queue>
#define MAX 200 + 1
using namespace std;

int n, r1, c1, r2, c2;
int visited[MAX][MAX];

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    queue<pair<int, int>> q;
    visited[r1][c1] = 1;
    q.push({r1, c1});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        if (x == r2 && y == c2) break;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }

    (visited[r2][c2]) ? cout << visited[r2][c2] - 1 : cout << -1;
    cout << "\n";

    return 0;
}
