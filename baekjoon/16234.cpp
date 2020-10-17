#include <iostream>
#include <queue>
#include <vector>
#define MAX 50 + 1
using namespace std;

int n, l, r;
int board[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> mv;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int sum = 0;
int time = 0;

bool flag = false;

void peopleMove() {
    flag = true;

    int num = sum / mv.size();
    while (!mv.empty()) {
        board[mv.front().first][mv.front().second] = num;
        mv.pop();
    }
}

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    mv.push({a, b});
    visited[a][b] = 1;
    sum += board[a][b];

    int x, y;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny]) continue;
            if (abs(board[x][y] - board[nx][ny]) > r ||
                abs(board[x][y] - board[nx][ny]) < l)
                continue;

            visited[nx][ny] = 1;
            mv.push({nx, ny});
            q.push({nx, ny});
            sum += board[nx][ny];
        }
    }
    if (mv.size() == 1)
        mv.pop();
    else
        peopleMove();

    sum = 0;

    return;
}

void resetVisit() {
    flag = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) visited[i][j] = 0;
    return;
}

int main() {
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];

    while (1) {
        resetVisit();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j]) bfs(i, j);

        if (!flag)
            break;
        else
            time++;
    }

    cout << time << "\n";
    return 0;
}
