#include <iostream>
#include <queue>
using namespace std;
#define MAX 55

int top_x, bottom_x;
int r, c, t;
int board[MAX][MAX];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void wind_top() {
    int x = top_x;
    queue<int> q;

    q.push(board[x][1]);
    board[x][1] = 0;
    for (int i = 2; i < c; i++) {
        q.push(board[x][i]);
        board[x][i] = q.front();
        q.pop();
    }

    for (int j = x - 1; j > 0; j--) {
        q.push(board[j][c - 1]);
        board[j][c - 1] = q.front();
        q.pop();
    }

    for (int i = c - 1; i >= 0; i--) {
        q.push(board[0][i]);
        board[0][i] = q.front();
        q.pop();
    }

    for (int j = 1; j < x; j++) {
        q.push(board[j][0]);
        board[j][0] = q.front();
        q.pop();
    }
}

void wind_bottom() {
    int x = bottom_x;
    queue<int> q;
    q.push(board[x][1]);
    board[x][1] = 0;

    for (int i = 2; i < c; i++) {
        q.push(board[x][i]);
        board[x][i] = q.front();
        q.pop();
    }

    for (int j = x + 1; j < r - 1; j++) {
        q.push(board[j][c - 1]);
        board[j][c - 1] = q.front();
        q.pop();
    }

    for (int i = c - 1; i >= 0; i--) {
        q.push(board[r - 1][i]);
        board[r - 1][i] = q.front();
        q.pop();
    }

    for (int j = r - 2; j > x; j--) {
        q.push(board[j][0]);
        board[j][0] = q.front();
        q.pop();
    }
}

void spread() {
    int spread_board[MAX][MAX] = {
        0,
    };
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (board[i][j]) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if (board[nx][ny] == -1) continue;
                    spread_board[nx][ny] += board[i][j] / 5;
                    spread_board[i][j] -= board[i][j] / 5;
                }
            }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) board[i][j] += spread_board[i][j];

    wind_top();
    wind_bottom();
}

int main() {
    bool flag = false;
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1)
                if (!flag) {
                    flag = true;
                    top_x = i;
                } else
                    bottom_x = i;
        }

    while (t--) spread();

    int cnt = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (board[i][j] && board[i][j] != -1) cnt += board[i][j];

    cout << cnt << "\n";
}
