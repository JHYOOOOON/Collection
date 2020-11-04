#include <iostream>
#define MAX 100000 + 1
using namespace std;

int n, m;
int board[MAX] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> board[i];
        board[i] += board[i - 1];
    }

    cin >> m;
    int a, b;
    while (m--) {
        cin >> a >> b;
        cout << board[b] - board[a - 1] << "\n";
    }

    return 0;
}
