#include <iostream>
#define MAX 1000 + 1
using namespace std;

int n;
int board[MAX];
int d[MAX];
int r[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];

    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j <= i; j++)
            if (board[j] < board[i] && d[i] < d[j] + 1) d[i] = d[j] + 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        r[i] = 1;
        for (int j = n - 1; j >= i; j--)
            if (board[j] < board[i] && r[i] < r[j] + 1) r[i] = r[j] + 1;
    }

    int mx = 0;

    for (int i = 0; i < n; i++)
        if (mx < d[i] + r[i] - 1) mx = d[i] + r[i] - 1;

    cout << mx << "\n";
    return 0;
}
