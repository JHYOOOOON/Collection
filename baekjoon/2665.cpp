#include <iostream>
#include <queue>
#include <tuple>
#define MAX 50 + 1
using namespace std;
using tiii = tuple<int, int, int>;

char board[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n;

int blackRoom(int a, int b) {
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    visited[a][b] = 0;
    pq.push({0, a, b});

    int x, y, cnt;
    while (!pq.empty()) {
        tie(cnt, x, y) = pq.top();

        if (x == n - 1 && y == n - 1) return cnt;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = 1;
            (board[nx][ny] == '0') ? pq.push({cnt + 1, nx, ny})
                                   : pq.push({cnt, nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];

    cout << blackRoom(0, 0) << "\n";

    return 0;
}
