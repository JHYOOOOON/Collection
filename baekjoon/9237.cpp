#include <algorithm>
#include <iostream>
#define MAX 100000 + 1
using namespace std;

int n;
int board[MAX];
int mx = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];
    sort(board, board + n, greater<int>());

    int cnt = 2;
    for (int i = 0; i < n; i++) {
        mx = max(mx, cnt + board[i]);
        cnt++;
    }

    cout << mx << "\n";
    return 0;
}
