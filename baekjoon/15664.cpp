#include <algorithm>
#include <iostream>
#define MAX 10000 + 1
using namespace std;

int n, m;
int board[MAX];
bool isused[9];
int ans[9];

void select(int depth, int start) {
    if (depth == m) {
        for (int i = 0; i < m; i++) cout << ans[i] << ' ';
        cout << "\n";
        return;
    }

    int before = -1;
    for (int i = start; i < n; i++) {
        if (!isused[i] && (i == 0 || before != board[i])) {
            before = board[i];
            ans[depth] = board[i];
            isused[i] = 1;
            select(depth + 1, i + 1);
            isused[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];
    sort(board, board + n);

    select(0, 0);

    return 0;
}
