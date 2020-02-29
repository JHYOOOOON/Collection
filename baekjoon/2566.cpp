#include <bits/stdc++.h>
using namespace std;

int main()
{
    int board[9][9];
    int mx = 0;
    pair<int, int> mx_idx;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (mx < board[i][j])
            {
                mx = board[i][j];
                mx_idx = {i, j};
            }
        }

    cout << mx << "\n"
         << mx_idx.first + 1 << ' ' << mx_idx.second + 1 << "\n";
    return 0;
}
