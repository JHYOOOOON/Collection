#include <iostream>
#include <queue>
#include <vector>
#define MAX 123456
using namespace std;

int board[51][51], visited[51][51];
vector<pair<int, int>> virus;
queue<pair<int, int>> q;
bool isused[11];
int n, m;
int time = MAX;
int blank = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs() {
    int t = 0;
    int tmp_blank = 0;

    int x, y;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny] != -1 || board[nx][ny] == 1) continue;

            if (board[nx][ny] == 0) tmp_blank++;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});

            if (visited[nx][ny] > t && board[nx][ny] != 2) t = visited[nx][ny];
        }
    }

    if (blank == tmp_blank)
        if (time > t) time = t;

    return;
}

void setup() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) visited[i][j] = -1;

    for (int i = 0; i < virus.size(); i++)
        if (isused[i]) {
            q.push({virus[i].first, virus[i].second});
            visited[virus[i].first][virus[i].second] = 0;
        }

    bfs();
    return;
}

void select(int index, int cnt) {
    if (cnt == m) setup();

    for (int i = index; i < virus.size(); i++) {
        if (!isused[i]) {
            isused[i] = 1;
            select(i + 1, cnt + 1);
            isused[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2)
                virus.push_back({i, j});
            else if (board[i][j] == 0)
                blank++;
        }

    select(0, 0);
    (time == MAX) ? cout << -1 << "\n" : cout << time << "\n";
    return 0;
}
