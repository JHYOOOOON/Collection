#include <iostream>
#define MAX 10 + 5
#define INF 10000000 + 5
using namespace std;

int board[MAX][MAX];
bool visited[MAX];
int start, n;
int mn = INF;

void round(int cnt, int before, int cost) {
    if (cnt == n - 1) {
        if (board[before][start]) mn = min(mn, cost + board[before][start]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && board[before][i]) {
            visited[before] = 1;
            round(cnt + 1, i, cost + board[before][i]);
            visited[before] = 0;
        }
    }
    return;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i] && board[i][j]) {
                start = i;
                visited[i] = 1;
                round(1, j, board[i][j]);
                visited[i] = 0;
            }
        }
    }

    cout << mn << "\n";

    return 0;
}
