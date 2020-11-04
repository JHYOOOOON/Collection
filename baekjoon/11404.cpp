#include <iostream>
#define INF 10000000
#define MAX 100 + 1
using namespace std;

int n, m;
int board[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) fill(board[i], board[i] + 1 + n, INF);

    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        board[a][b] = min(board[a][b], c);
    }

    for (int i = 1; i <= n; i++) board[i][i] = 0;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            (board[i][j] == INF) ? cout << "0 " : cout << board[i][j] << ' ';
        cout << "\n";
    }
    return 0;
}
