#include <algorithm>
#include <iostream>
using namespace std;

int m, n;
int board[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> board[i];
    sort(board, board + n);

    int ans = 0;
    int left = 1, right = board[n - 1];
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) cnt += board[i] / mid;

        if (cnt >= m) {
            ans = mid;
            left = mid + 1;
        } else
            right = mid - 1;
    }

    cout << ans << "\n";

    return 0;
}
