#include <iostream>
#include <vector>
using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> board(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> board[i];
        board[i] += board[i - 1];
    }

    int i, j;
    while (m--) {
        cin >> i >> j;
        cout << board[j] - board[i - 1] << "\n";
    }

    return 0;
}
