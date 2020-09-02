#include <iostream>
#define MAX 100000
using namespace std;

int main() {
    int n;
    int board[MAX][3];

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) cin >> board[i][j];

    int dp_max[2][3];
    int dp_min[2][3];
    dp_max[0][0] = dp_min[0][0] = board[0][0];
    dp_max[0][1] = dp_min[0][1] = board[0][1];
    dp_max[0][2] = dp_min[0][2] = board[0][2];

    for (int i = 1; i < n; i++) {
        dp_max[1][0] = max(dp_max[0][0], dp_max[0][1]) + board[i][0];
        dp_max[1][1] =
            max(dp_max[0][0], max(dp_max[0][1], dp_max[0][2])) + board[i][1];
        dp_max[1][2] = max(dp_max[0][1], dp_max[0][2]) + board[i][2];

        dp_min[1][0] = min(dp_min[0][0], dp_min[0][1]) + board[i][0];
        dp_min[1][1] =
            min(dp_min[0][0], min(dp_min[0][1], dp_min[0][2])) + board[i][1];
        dp_min[1][2] = min(dp_min[0][1], dp_min[0][2]) + board[i][2];

        dp_max[0][0] = dp_max[1][0];
        dp_max[0][1] = dp_max[1][1];
        dp_max[0][2] = dp_max[1][2];

        dp_min[0][0] = dp_min[1][0];
        dp_min[0][1] = dp_min[1][1];
        dp_min[0][2] = dp_min[1][2];
    }

    int mx = max(dp_max[0][0], max(dp_max[0][1], dp_max[0][2]));
    int mn = min(dp_min[0][0], min(dp_min[0][1], dp_min[0][2]));

    cout << mx << " " << mn << "\n";
    return 0;
}
