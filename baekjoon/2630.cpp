#include <iostream>
using namespace std;

int board[130][130];
int black = 0, white = 0;

void paper(int x, int y, int n) {
    int cnt = 0;
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (board[i][j]) cnt++;
    if (!cnt)
        white++;
    else if (cnt == n * n)
        black++;
    else {
        paper(x, y, n / 2);
        paper(x, y + n / 2, n / 2);
        paper(x + n / 2, y, n / 2);
        paper(x + n / 2, y + n / 2, n / 2);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];

    paper(0, 0, n);
    cout << white << "\n" << black << "\n";
    return 0;
}
