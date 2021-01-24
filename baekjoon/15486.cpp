#include <iostream>
#define MAX 1500000 + 2
#define T first
#define P second
using namespace std;

int n;
pair<int, int> board[MAX];
int d[MAX] = {0};

int main() {
    cin >> n;

    int t, p;
    for (int i = 1; i <= n; i++) {
        cin >> t >> p;
        board[i] = {t, p};
    }

    int mx = 0;
    for (int i = 1; i <= n + 1; i++) {
        mx = max(mx, d[i]);
        if (i + board[i].T <= n + 1) {
            d[i + board[i].T] = max(mx + board[i].P, d[i + board[i].T]);
        }
    }

    cout << mx << "\n";

    return 0;
}
