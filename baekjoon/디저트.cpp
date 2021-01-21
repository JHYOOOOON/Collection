#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int board[11][100001];  // [디저트][날짜]
int d[11][100001] = {0};

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        for (int j = 1; j <= n; j++) cin >> board[i][j];

    // 1일 초기화
    for (int i = 0; i < m; i++) d[i][1] = board[i][1];

    // i: 날짜, j: i-1일 디저트, k: i일 디저트
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < m; k++)
                d[k][i] = (j == k) ? max(d[k][i], d[j][i - 1] + board[k][i] / 2)
                                   : max(d[k][i], d[j][i - 1] + board[k][i]);

    int mx = 0;
    for (int i = 0; i < m; i++) mx = max(mx, d[i][n]);

    cout << mx << "\n";
    return 0;
}
