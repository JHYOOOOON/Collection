#include <iostream>
#define MAX 100
#define INF 987654321
using namespace std;

int dist, idx, start;
int board[MAX][MAX];

void check(int x, int y, int cnt) {
    if (x == 99) {
        if (dist > cnt) {
            idx = start;
            dist = cnt;
        }
        return;
    }

    board[x][y] = 0;

    if (board[x][y - 1] && y - 1 >= 0)
        check(x, y - 1, cnt + 1);
    else if (board[x][y + 1] && y + 1 < MAX)
        check(x, y + 1, cnt + 1);
    else
        check(x + 1, y, cnt + 1);

    board[x][y] = 1;
}

void input() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) cin >> board[i][j];
    return;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int test_case, T;
    for (test_case = 1; test_case <= 10; ++test_case) {
        cin >> T;
        dist = INF;
        input();
        for (int i = 99; i >= 0; i--) 
            if (board[0][i]) {
                start = i;
                check(0, i, 1);
            }

        cout << '#' << T << ' ' << idx << "\n";
    }

    return 0;
}
