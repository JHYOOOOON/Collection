#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 500 + 2
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int a, b;

    vector<pair<int, int>> board;
    int d[MAX];

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        board.push_back({a, b});
    }

    sort(board.begin(), board.end());

    int mx = 0;
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (board[i].second > board[j].second && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                mx = max(mx, d[i]);
            }
        }
    }

    cout << n - mx << "\n";
    return 0;
}
