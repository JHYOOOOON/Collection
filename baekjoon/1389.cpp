#include <iostream>
#define MAX 100 + 1
#define INF 500000
using namespace std;

int n, m;
int d[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) fill(d[i], d[i] + n + 1, INF);
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    int a, b;
    while (m--) {
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int mx = INF;
    int person = 0;
    int cnt;
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        for (int j = 1; j <= n; j++) {
            cnt += d[i][j];
        }
        if (mx > cnt) {
            mx = cnt;
            person = i;
        }
    }

    cout << person << "\n";

    return 0;
}
