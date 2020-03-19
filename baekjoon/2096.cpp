#include <bits/stdc++.h>
using namespace std;

int board[3], mx[2][3], mn[2][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> board[0] >> board[1] >> board[2];
        mx[1][0] = max(mx[0][0], mx[0][1]) + board[0];
        mx[1][1] = max(mx[0][0], max(mx[0][1], mx[0][2])) + board[1];
        mx[1][2] = max(mx[0][2], mx[0][1]) + board[2];

        mx[0][0] = mx[1][0];
        mx[0][1] = mx[1][1];
        mx[0][2] = mx[1][2];

        mn[1][0] = min(mn[0][0], mn[0][1]) + board[0];
        mn[1][1] = min(mn[0][0], min(mn[0][1], mn[0][2])) + board[1];
        mn[1][2] = min(mn[0][2], mn[0][1]) + board[2];

        mn[0][0] = mn[1][0];
        mn[0][1] = mn[1][1];
        mn[0][2] = mn[1][2];
    }

    cout << max(mx[0][0], max(mx[0][1], mx[0][2]))
         << ' '
         << min(mn[0][0], min(mn[0][1], mn[0][2]));
    return 0;
}
