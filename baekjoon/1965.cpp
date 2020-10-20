#include <iostream>
#define MAX 1000 + 1
using namespace std;

int n;
int box[MAX] = {0};
int dp[MAX] = {0};
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> box[i];

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
            if (box[i] > box[j]) dp[i] = max(dp[i], dp[j] + 1);
    }

    int mx = 0;
    for (int i = 0; i < n; i++) mx = max(mx, dp[i]);

    cout << mx << "\n";
    return 0;
}
