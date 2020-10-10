#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 2000000000
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> board(n);
    for (int i = 0; i < n; i++) cin >> board[i];
    sort(board.begin(), board.end());

    int mn = MAX;
    int left = 0;
    int right = 0;
    while (left <= right && right < n) {
        if (left == right) right++;
        if (board[right] - board[left] >= m) {
            if (board[right] - board[left] < mn)
                mn = board[right] - board[left];
            left++;
        } else {
            right++;
        }
    }

    cout << mn << "\n";

    return 0;
}
