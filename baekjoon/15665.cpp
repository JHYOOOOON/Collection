#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int board[8];
int ans[8];

void select(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << ans[i] << ' ';
        cout << "\n";
        return;
    }

    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (prev != board[i]) {
            ans[cnt] = board[i];
            prev = board[i];
            select(cnt + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];

    sort(board, board + n);
    select(0);

    return 0;
}
