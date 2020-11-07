#include <iostream>
#include <vector>
#define MAX 50 + 5
#define INF 250

using namespace std;

int n;
int d[MAX][MAX] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) fill(d[i], d[i] + n + 1, INF);
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    int a, b;
    while (1) {
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        d[a][b] = 1;
        d[b][a] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    vector<vector<int>> ans(n + 1);
    int mn = INF;
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            mx = max(mx, d[i][j]);
        }
        mn = min(mn, mx);
        ans[mx].push_back(i);
    }

    cout << mn << ' ' << ans[mn].size() << "\n";
    for (auto a : ans[mn]) cout << a << ' ';
    return 0;
}
