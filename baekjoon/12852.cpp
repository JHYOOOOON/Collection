#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int n;
int dp[MAX] = {0}, before[MAX];

int main() {
    cin >> n;

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        before[i] = i - 1;
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            before[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            before[i] = i / 3;
        }
    }

    cout << dp[n] << "\n";
    int idx = n;
    while (1) {
        cout << idx << ' ';
        if (idx == 1) break;
        idx = before[idx];
    }

    return 0;
}
