#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> board(n + 1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) cin >> board[i];

    int right = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        while (sum < m && right <= n) {
            sum += board[right++];
        }
        if (sum == m) cnt++;
        sum -= board[i];
    }

    cout << cnt << "\n";
    return 0;
}
