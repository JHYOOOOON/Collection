#include <iostream>
#include <vector>
using namespace std;

int n, m;
char tmp;
int mx = 0;

int board[1000][1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            board[i][j] = tmp - '0';
        }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (board[i][j] != 0)
                board[i][j] += min(board[i - 1][j],
                                   min(board[i - 1][j - 1], board[i][j - 1]));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) mx = max(mx, board[i][j]);
    cout << mx * mx << "\n";
    return 0;
}
