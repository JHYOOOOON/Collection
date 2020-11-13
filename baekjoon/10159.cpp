#include <iostream>
#define MAX 100 + 5
#define INF 10000 + 5
using namespace std;

int n, m;
int board[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) board[i][j] = INF;

    for (int i = 1; i <= n; i++) board[i][i] = 0;

    int a, b;
    while (m--) {
        cin >> a >> b;
        board[a][b] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (board[i][j] > board[i][k] + board[k][j])
                    board[i][j] = board[i][k] + board[k][j];

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if (board[i][j] == INF && board[j][i] == INF) cnt++;
        cout << cnt << "\n";
    }

    return 0;
}
