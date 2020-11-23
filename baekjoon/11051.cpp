#include <iostream>
#define MOD 10007
#define MAX 1000 + 1
using namespace std;

int n, k;
int d[MAX][MAX] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            if (i == j || j == 0) {
                d[i][j] = 1;
                continue;
            }
            d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % MOD;
        }

    cout << d[n][k] << "\n";
}
