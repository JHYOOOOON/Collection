#include <iostream>
#include <queue>
#define dice first
#define cnt second
#define MAX 100 + 1
using namespace std;

int n, m;
int board[MAX] = {0};
bool visited[MAX];

int main() {
    cin >> n >> m;

    for (int i = 1; i < MAX; i++) board[i] = i;

    int a, b;
    while (n--) {
        cin >> a >> b;
        board[a] = b;
    }

    while (m--) {
        cin >> a >> b;
        board[a] = b;
    }

    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = 1;
    int d, c;
    while (!q.empty()) {
        d = q.front().dice;
        c = q.front().cnt;
        q.pop();
        if (d == 100) {
            cout << c << "\n";
            return 0;
        }
        for (int i = 1; i <= 6; i++) {
            int nd = d + i;
            if (nd > 100 || visited[nd]) continue;
            q.push({board[nd], c + 1});
            visited[board[nd]] = 1;
        }
    }
    return 0;
}
