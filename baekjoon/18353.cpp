#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> board(n);
    for (int i = 0; i < n; i++) cin >> board[i];

    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (board[i] < board[j]) dp[i] = max(dp[i], dp[j] + 1);

    int mx = 0;
    for (int i = 0; i < n; i++)
        if (mx < dp[i]) mx = dp[i];
    cout << n - mx << "\n";
    return 0;
}
