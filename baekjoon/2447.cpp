#include <iostream>
#define MAX 2500
using namespace std;

char board[MAX][MAX];

void star(int size, int r, int c) {
    if (size == 1) {
        board[r][c] = '*';
        return;
    }

    int l = size / 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            star(l, r + (i * l), c + (j * l));
        }
}

int main() {
    int n;
    cin >> n;
    star(n, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (board[i][j] == '*') ? cout << '*' : cout << ' ';
        }
        cout << "\n";
    }
    return 0;
}
