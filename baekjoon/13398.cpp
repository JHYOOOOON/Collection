#include <iostream>
#define MAX 100000 + 1
using namespace std;

int n;
int board[MAX];
int d[MAX][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];

    d[0][0] = d[0][1] = board[0];

    int mx = board[0];
    for (int i = 1; i < n; i++) {
        d[i][0] = max(d[i - 1][0] + board[i], board[i]);
        d[i][1] = max(d[i - 1][0], d[i - 1][1] + board[i]);
        mx = max(mx, max(d[i][0], d[i][1]));
    }

    cout << mx << "\n";

    return 0;
}
