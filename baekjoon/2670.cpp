#include <cmath>
#include <iostream>
#define MAX 10000 + 1
using namespace std;

int n;
double board[MAX], d[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];

    d[0] = board[0];
    for (int i = 1; i < n; i++) {
        d[i] = max(board[i], board[i] * d[i - 1]);
    }

    double mx = 0;
    for (int i = 0; i < n; i++) mx = max(mx, d[i]);

    printf("%0.3f\n", mx);
    return 0;
}
