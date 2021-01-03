#include <algorithm>
#include <iostream>
#define MAX 10
using namespace std;

int n, m;
int board[MAX];
int num[MAX];

void check(int cnt, int before) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << num[i] << ' ';
        cout << "\n";
        return;
    }

    int prev = -1;
    for (int i = before; i < n; i++) {
        if (prev != board[i]) {
            num[cnt] = board[i];
            prev = board[i];
            check(cnt + 1, i);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];

    sort(board, board + n);

    check(0, 0);

    return 0;
}
