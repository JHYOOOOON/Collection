#include <iostream>
#define MAX 505
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a[MAX][MAX] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);

    int mx = 0;
    for (int i = 1; i <= n; i++)
        if (mx < a[n][i]) mx = a[n][i];

    cout << mx << "\n";

    return 0;
}
