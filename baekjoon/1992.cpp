#include <iostream>
using namespace std;

char board[65][65];

void video(int x, int y, int n) {
    int cnt = 0;
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (board[i][j] == '1') cnt++;
    if (!cnt)
        cout << 0;
    else if (cnt == n * n)
        cout << 1;
    else {
        cout << "(";
        video(x, y, n / 2);
        video(x + n / 2, y, n / 2);
        video(x, y + n / 2, n / 2);
        video(x + n / 2, y + n / 2, n / 2);
        cout << ")";
    }
    return;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[j][i];
    video(0, 0, n);

    return 0;
}
