#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 1000 + 5
using namespace std;

int d[MAX];
int board[MAX];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> board[i];

    int mx = 0;
    for (int i = 0; i < n; i++) {
        d[i] = board[i];
        for (int j = 0; j < i; j++) {
            if (board[j] > board[i] && d[i] < d[j] + board[i]) {
                d[i] = d[j] + board[i];
            }
        }
        mx = max(mx, d[i]);
    }

    cout << mx << "\n";

    return 0;
}
