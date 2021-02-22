#include <iostream>
#define MAX 1000 + 1
#define INF 123456789
using namespace std;

int n;
char board[MAX];
int d[MAX];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];

    fill(d, d + n, INF);
    d[0] = 0;

    for (int i = 0; i < n; i++) {
        if (d[i] == INF) continue;

        char nxt;
        if (board[i] == 'B')
            nxt = 'O';
        else if (board[i] == 'O')
            nxt = 'J';
        else
            nxt = 'B';

        for (int j = i + 1; j < n; j++)
            if (board[j] == nxt) d[j] = min(d[j], d[i] + (j - i) * (j - i));
    }

    (d[n - 1] == INF) ? cout << "-1\n" : cout << d[n - 1] << "\n";

    return 0;
}
