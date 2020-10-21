#include <iostream>
#define MAX 1024 + 1
using namespace std;

int n, m;
int board[MAX][MAX] = {0};
int dp[MAX][MAX] = {0};
int pre = 0, tmp;
int x1, x2, y1, y2;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> board[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] =
                dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + board[i][j];

    while (m--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] +
                    dp[x1 - 1][y1 - 1]
             << "\n";
    }
    return 0;
}
