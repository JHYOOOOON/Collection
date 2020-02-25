#include <bits/stdc++.h>
using namespace std;

bool board[51][51];
bool visit[51][51];

int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

int land(int w, int h)
{
    int cnt = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> board[i][j];
            visit[i][j] = false;
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (board[i][j] && !visit[i][j])
            {
                cnt++;
                queue<pair<int, int>> q;
                visit[i][j] = true;
                q.push({i, j});
                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();
                    for (int i = 0; i < 8; i++)
                    {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];
                        if (board[nx][ny] && !visit[nx][ny] && nx >= 0 && nx < h && ny >= 0 && ny < w)
                        {
                            visit[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    return cnt;
}

int main()
{
    int w, h;
    while (1)
    {
        cin >> w >> h;
        if (!w && !h)
            return 0;

        cout << land(w, h) << "\n";
    }
}
