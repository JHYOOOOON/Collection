#include <iostream>
#define MAX 20
#define T first
#define P second
using namespace std;

int main() {
    int n;
    cin >> n;

    pair<int, int> board[MAX];
    int t, p;
    for (int i = 1; i <= n; i++) {
        cin >> t >> p;
        board[i] = {t, p};
    }

    int dp[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        if (i + board[i].T <= n + 1)
            dp[i + board[i].T] = max(dp[i + board[i].T], dp[i] + board[i].P);
        dp[i + 1] = max(dp[i], dp[i + 1]);
    }

    cout << dp[n + 1] << "\n";
    return 0;
}
