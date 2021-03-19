#include <cstring>
#include <iostream>
#define MAX 50 + 1
#define INF 10
using namespace std;

struct fireball {
    int m, s, d, cnt;
};

int N, M, K;
fireball board[MAX][MAX], tmp[MAX][MAX];

// x, 1, 2, 3, 4, 5, 6, 7, 0
int dx[] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};

// 파이어볼 정리
void div() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (tmp[i][j].m == 0)
                board[i][j] = {0, 0, 0, 0};
            else if (tmp[i][j].cnt == 1) {
                board[i][j] = tmp[i][j];
            } else {
                board[i][j].m = tmp[i][j].m / 5;
                if (board[i][j].m == 0) {
                    board[i][j] = {0, 0, 0, 0};
                    continue;
                }
                board[i][j].s = tmp[i][j].s / tmp[i][j].cnt;
                board[i][j].cnt = 4;
                board[i][j].d = tmp[i][j].d;
            }
        }

    memset(tmp, 0, sizeof(tmp));
}

// 파이어볼 한개씩 이동
void go(int i, int j, int d) {
    int ns = board[i][j].s % N;
    int nx = i + dx[d] * ns;
    int ny = j + dy[d] * ns;
    if (nx > N) nx -= N;
    if (ny > N) ny -= N;
    if (nx < 1) nx += N;
    if (ny < 1) ny += N;

    tmp[nx][ny].m += board[i][j].m;
    tmp[nx][ny].s += board[i][j].s;
    if (tmp[nx][ny].d == 0)
        tmp[nx][ny].d = d;
    else if (tmp[nx][ny].d != INF && tmp[nx][ny].d % 2 != d % 2)
        tmp[nx][ny].d = INF;
    tmp[nx][ny].cnt++;

    return;
}

// 파이어볼 이동
void move() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (board[i][j].cnt == 0) continue;
            if (board[i][j].cnt == 1) {
                go(i, j, board[i][j].d);
            } else {
                int dir = (board[i][j].d == INF) ? 1 : 2;
                for (dir; dir <= 8; dir += 2) go(i, j, dir);
            }
        }
}

// 입력받음
void input() {
    int r, c, m, s, d;
    while (M--) {
        cin >> r >> c >> m >> s >> d;
        if (d == 0) d = 8;
        board[r][c] = {m, s, d, 1};
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    input();

    while (K--) {
        move();
        div();
    }

    int sum = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) sum += board[i][j].m * board[i][j].cnt;

    cout << sum << "\n";
    return 0;
}
