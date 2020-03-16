#include <bits/stdc++.h>
using namespace std;
#define MOD 9901

int dp[100001][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    dp[0][0] = dp[0][1] = dp[0][2] = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
    }

    cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % MOD << "\n";
    return 0;
}
