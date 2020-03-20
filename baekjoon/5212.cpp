#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int r, c;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    char board[11][11];
    vector<pair<int, int>> v;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> board[i][j];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == '.')
                continue;
            int cnt = 0;
            for (int a = 0; a < 4; a++)
            {
                int nx = dx[a] + i;
                int ny = dy[a] + j;
                if (nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] == '.')
                    cnt++;
            }
            if (cnt >= 3)
                v.push_back({i, j});
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        auto cur = v[i];
        board[cur.first][cur.second] = '.';
    }
    int s1 = r, s2 = c, l1 = 0, l2 = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == '.')
                continue;
            if (i < s1)
                s1 = i;
            if (j < s2)
                s2 = j;
            if (l1 < i)
                l1 = i;
            if (l2 < j)
                l2 = j;
        }
    for (int i = s1; i <= l1; i++)
    {
        for (int j = s2; j <= l2; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}
