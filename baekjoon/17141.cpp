#include <iostream>
#include <queue>
#include <vector>

#define MAX 50 + 5
#define INF 2500

using namespace std;

int n, m;
int board[MAX][MAX];
int visited[MAX][MAX];

vector<pair<int, int>> virus;
vector<bool> isused;

int mn = INF;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void reset() {
    for (int i = 0; i < n; i++) fill(visited[i], visited[i] + n, -1);
    return;
}

void check() {
    bool flag = false;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 1 && visited[i][j] == -1) {
                flag = true;
                break;
            } else {
                mx = max(mx, visited[i][j]);
            }
        }
        if (flag) break;
    }

    if (!flag) mn = min(mn, mx);
}

void spread() {
    reset();
    queue<pair<int, int>> q;
    int x, y;

    for (int i = 0; i < virus.size(); i++)
        if (isused[i]) {
            q.push(virus[i]);
            visited[virus[i].first][virus[i].second] = 0;
        }

    int mx = 0;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny] != -1 || board[nx][ny] == 1) continue;

            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }

    check();
}

void select(int depth, int start) {
    if (depth == m) {
        spread();
        return;
    }

    for (int i = start; i < virus.size(); i++) {
        if (!isused[i]) {
            isused[i] = 1;
            select(depth + 1, i + 1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    reset();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) virus.push_back({i, j});
        }

    isused.resize(virus.size());
    select(0, 0);

    (mn == INF) ? cout << -1 << "\n" : cout << mn << "\n";

    return 0;
}
