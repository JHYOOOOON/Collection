#include <cstring>
#include <iostream>
using namespace std;

int n, m, k, mx_sum, sum, ans, max_price;
bool board[21][21], visited[21][21];
pair<int, int> start;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void go(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (visited[nx][ny]) continue;
        if (abs(start.first - nx) + abs(start.second - ny) > k - 1) continue;

        visited[nx][ny] = 1;
        sum += board[nx][ny] * m;
        go(nx, ny);
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        memset(visited, 0, sizeof(visited));
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
                if (board[i][j]) max_price += m;
            }

        k = 22;
        ans = 1;
        int oper = 0;
        while (k--) {
            mx_sum = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    memset(visited, 0, sizeof(visited));
                    sum = board[i][j] * m;
                    visited[i][j] = 1;
                    start = {i, j};
                    go(i, j);
                    mx_sum = max(mx_sum, sum);
                }

            oper = k * k + (k - 1) * (k - 1);
            if (mx_sum - oper >= 0) ans = max(ans, mx_sum / m);
            if (ans == max_price / m || k == 2) break;
        }

        cout << '#' << test_case << ' ' << ans << "\n";
    }
    return 0;
}
