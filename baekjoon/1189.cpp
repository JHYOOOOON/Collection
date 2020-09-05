#include <iostream>
using namespace std;

int r, c, k;
char road[6][6];
bool visited[6][6];
int cnt = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void func(int len, int a, int b) {
    if (a == 0 && b == c - 1) {
        if (len == k) cnt++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = a + dx[i];
        int ny = b + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (road[nx][ny] == 'T' || visited[nx][ny]) continue;
        visited[nx][ny] = 1;
        func(len + 1, nx, ny);
        visited[nx][ny] = 0;
    }
}

int main() {
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> road[i][j];

    visited[r - 1][0] = 1;
    func(1, r - 1, 0);

    cout << cnt << "\n";
    return 0;
}
