#include <iostream>
#define MAX 1000 + 1
using namespace std;

int land[MAX][MAX] = {0};
int dp[MAX][MAX];
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cin >> land[i][j];

    int mx = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (land[i][j])
                dp[i][j] = 0;
            else
                dp[i][j] =
                    min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
            mx = max(mx, dp[i][j]);
        }
    }

    cout << mx << "\n";
}
