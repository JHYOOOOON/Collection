#include <iostream>
#define MAX 1000 + 1
using namespace std;

int n;
int board[MAX];
int d[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];
    fill(d, d + MAX, MAX);

    d[0] = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 1; j <= board[i]; j++) d[i + j] = min(d[i + j], d[i] + 1);

    d[n - 1] == MAX ? cout << -1 << "\n" : cout << d[n - 1] << "\n";
    return 0;
}
