#include <iostream>
#include <queue>
#define MAX 10 + 1
using namespace std;

struct ball {
    int cnt;
    int rx, ry, bx, by;
};

int irx, iry, ibx, iby;

int n, m, ans = -1;
char board[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                irx = i;
                iry = j;
            } else if (board[i][j] == 'B') {
                ibx = i;
                iby = j;
            }
        }

    visited[irx][iry][ibx][iby] = 1;
    queue<ball> q;
    q.push({0, irx, iry, ibx, iby});
    while (!q.empty()) {
        ball cur = q.front();
        q.pop();

        if (cur.cnt > 10) break;
        if (board[cur.rx][cur.ry] == 'O') {
            cout << cur.cnt << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int rx = cur.rx, ry = cur.ry;
            int bx = cur.bx, by = cur.by;
            while (1) {
                rx += dx[i], ry += dy[i];
                bx += dx[i], by += dy[i];
                if (board[rx][ry] == '#' || board[bx][by] == '#') {
                    if (board[rx][ry] == '#' && board[bx][by] == '#') {
                        rx -= dx[i], ry -= dy[i];
                        bx -= dx[i], by -= dy[i];
                        break;
                    } else if (board[rx][ry] == '#') {
                        rx -= dx[i], ry -= dy[i];
                        if (rx == bx && ry == by) {
                            bx -= dx[i], by -= dy[i];
                            break;
                        }
                    } else if (board[bx][by] == '#') {
                        bx -= dx[i], by -= dy[i];
                        if (rx == bx && ry == by) {
                            rx -= dx[i], ry -= dy[i];
                            break;
                        }
                    }
                }

                if (board[bx][by] == 'O') break;
                if (board[rx][ry] == 'O') {
                    bool flag = true;
                    while (flag) {
                        bx += dx[i], by += dy[i];
                        if (board[bx][by] == 'O') {
                            flag = false;
                        } else if (board[bx][by] == '#') {
                            flag = false;
                            bx -= dx[i], by -= dy[i];
                        }
                    }
                    break;
                }
            }

            if (!visited[rx][ry][bx][by] && board[bx][by] != 'O') {
                visited[rx][ry][bx][by] = 1;
                q.push({cur.cnt + 1, rx, ry, bx, by});
            }
        }
    }

    cout << "-1\n";
    return 0;
}
