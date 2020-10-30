#include <iostream>
#include <queue>
#include <tuple>
#define MAX 125 + 1
#define INF 1300
using namespace std;
using tiii = tuple<int, int, int>;

int board[MAX][MAX];
int d[MAX][MAX];
priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n;

void reset() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) d[i][j] = INF;
}

void lostRupy() {
    d[1][1] = board[1][1];
    pq.push({d[1][1], 1, 1});

    int r, x, y;
    while (!pq.empty()) {
        tie(r, x, y) = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

            if (d[nx][ny] > r + board[nx][ny]) {
                d[nx][ny] = r + board[nx][ny];
                pq.push({d[nx][ny], nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int idx = 1;
    while (cin >> n) {
        reset();
        if (n == 0) break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) cin >> board[i][j];

        lostRupy();
        cout << "Problem " << idx++ << ": " << d[n][n] << "\n";
    }

    return 0;
}
