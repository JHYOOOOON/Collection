#include <iostream>
using namespace std;

int n, m, x, y, k;
int dice[4][3] = {
    {0, 0, 0},
    {0, 0, 0}, 
    {0, 0, 0}, 
    {0, 0, 0}
};
int board[21][21];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];

    int dir, tmp;
    while (k--) {
        cin >> dir;
        if (dir == 1) {
            if (y + 1 == m) continue;
            y++;
            tmp = dice[1][2];
            dice[1][2] = dice[1][1];
            dice[1][1] = dice[1][0];
            dice[1][0] = dice[3][1];
            dice[3][1] = tmp;
        } else if (dir == 2) {
            if (y - 1 == -1) continue;
            y--;
            tmp = dice[1][0];
            dice[1][0] = dice[1][1];
            dice[1][1] = dice[1][2];
            dice[1][2] = dice[3][1];
            dice[3][1] = tmp;
        } else if (dir == 3) {
            if (x - 1 == -1) continue;
            x--;
            tmp = dice[0][1];
            for (int i = 0; i < 3; i++) dice[i][1] = dice[i + 1][1];
            dice[3][1] = tmp;
        } else if (dir == 4) {
            if (x + 1 == n) continue;
            x++;
            tmp = dice[3][1];
            for (int i = 3; i > 0; i--) dice[i][1] = dice[i - 1][1];
            dice[0][1] = tmp;
        }

        if (board[x][y]) {
            dice[3][1] = board[x][y];
            board[x][y] = 0;
        } else
            board[x][y] = dice[3][1];

        cout << dice[1][1] << "\n";
    }
    return 0;
}
