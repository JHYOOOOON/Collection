#include <iostream>
#define MAX 1000 + 1
using namespace std;

int n, m;
bool board[MAX][MAX];
int d[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> n >> m;
        if (n == 0 and m == 0) break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) cin >> board[i][j];

        int mx_len = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (board[i][j]) {
                    d[i][j] =
                        min(d[i - 1][j], min(d[i - 1][j - 1], d[i][j - 1])) + 1;
                    mx_len = max(mx_len, d[i][j]);
                } else {
                    d[i][j] = 0;
                }
            }

        cout << mx_len << "\n";
    }
    return 0;
}
