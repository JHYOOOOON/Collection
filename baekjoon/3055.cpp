#include <iostream>
#include <queue>
#define MAX 55
#define X first
#define Y second
using namespace std;

int r, c;
pair<int, int> start;               // 고슴도치 시작 좌표
queue<pair<int, int>> water_start;  // 물 시작 좌표 큐
char board[MAX][MAX];               // 처음 맵 받음
int water[MAX][MAX];                // 물 시간 지나면 퍼지는 거
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
bool flag = false;  // 고슴도치가 비버의 굴에 도착했나 못했나

// 고슴도치 출발
void hedgehog() {
    // 고슴도치 도착 시간 담기
    int visited[MAX][MAX];
    for (int i = 0; i < r; i++) fill(visited[i], visited[i] + c, -1);

    queue<pair<int, int>> q;
    visited[start.X][start.Y] = 0;
    q.push(start);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            // 이미 방문했거나 돌이거나 물이거나
            if (visited[nx][ny] >= 0 || board[nx][ny] == '*' ||
                board[nx][ny] == 'X')
                continue;
            // 이미 해당 좌표에 물이 찼다면
            if (water[nx][ny] <= visited[cur.X][cur.Y] + 1 &&
                water[nx][ny] != -1)
                continue;
            // 비버의 굴이라면 도착 시간 출력
            if (board[nx][ny] == 'D') {
                cout << visited[cur.X][cur.Y] + 1 << "\n";
                flag = true;
                return;
            }
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
    return;
}

// 물 출발
void water_board() {
    while (!water_start.empty()) {
        auto cur = water_start.front();
        water_start.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            // 돌이거나 비버의 굴이라면
            if (board[nx][ny] == 'X' || board[nx][ny] == 'D' ||
                water[nx][ny] >= 0)
                continue;
            water[nx][ny] = water[cur.X][cur.Y] + 1;
            water_start.push({nx, ny});
        }
    }

    return;
}

int main() {
    cin >> r >> c;

    // 물 배열 -1로 초기화
    for (int i = 0; i < r; i++) fill(water[i], water[i] + c, -1);

    // board값 받으면서 고슴도치 시작 좌표, 물 시작 좌표 받아두기
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'S') start = {i, j};
            if (board[i][j] == '*') {
                water[i][j] = 0;
                water_start.push({i, j});
            }
        }

    // 물 출발 시키고 고슴도치 출발 시키기
    water_board();
    hedgehog();

    // 고슴도치가 비버의 굴에 못도착했으면 출력
    if (!flag) cout << "KAKTUS\n";
    return 0;
}
