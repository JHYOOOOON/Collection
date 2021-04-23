#include <iostream>
#define MAX 100000 + 1
using namespace std;

int n;
// 0: 증가, 1: 감소
int board[MAX], d[MAX][2];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> board[i];

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        d[i][0] = d[i][1] = 1;
        if (board[i] >= board[i - 1]) d[i][0] = d[i - 1][0] + 1;
        if (board[i] <= board[i - 1]) d[i][1] = d[i - 1][1] + 1;
        mx = max(mx, max(d[i][0], d[i][1]));
    }

    cout << mx << "\n";

    return 0;
}
