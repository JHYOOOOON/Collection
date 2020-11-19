#include <iostream>
using namespace std;

char board[3073][6144];

void star(int h, int x, int y) {
    if (h == 3) {
        board[x][y] = '*';
        board[x + 1][y - 1] = '*';
        board[x + 1][y + 1] = '*';
        for (int i = y - 2; i <= y + 2; i++) board[x + 2][i] = '*';
        return;
    }

    star(h / 2, x, y);
    star(h / 2, x + (h / 2), y - (h / 2));
    star(h / 2, x + (h / 2), y + (h / 2));
}

int main() {
    int n;
    cin >> n;

    star(n, 1, n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 2 * n; j++)
            if (board[i][j] != '*') board[i][j] = ' ';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 2 * n; j++) cout << board[i][j];
        cout << "\n";
    }

    return 0;
}
