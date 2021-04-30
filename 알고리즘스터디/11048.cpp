#include <iostream>
#define MAX 1000 + 1
using namespace std;

int n, m;
int board[MAX][MAX] = {0};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> board[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            board[i][j] +=
                max(board[i - 1][j], max(board[i - 1][j - 1], board[i][j - 1]));

    cout << board[n][m] << "\n";
    return 0;
}
