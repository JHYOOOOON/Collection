#include <algorithm>
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n;

    vector<pair<int, int>> board;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        board.push_back({a, b});
    }

    sort(board.begin(), board.end());
    int sum = 0;
    a = board[0].X;
    b = board[0].Y;
    for (int i = 1; i < n; i++) {
        if (board[i].X <= b) {
            b = max(b, board[i].Y);
        } else {
            sum += b - a;
            a = board[i].X;
            b = board[i].Y;
        }
    }
    sum += b - a;
    cout << sum << "\n";

    return 0;
}
