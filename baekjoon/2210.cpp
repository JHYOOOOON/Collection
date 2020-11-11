#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#define MAX 5 + 1
using namespace std;

set<string> s;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int board[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) cin >> board[i][j];

    int x, y;
    string n;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            queue<tuple<int, int, string>> q;
            q.push({i, j, to_string(board[i][j])});
            while (!q.empty()) {
                tie(x, y, n) = q.front();
                q.pop();
                for (int cur = 0; cur < 4; cur++) {
                    int nx = x + dx[cur];
                    int ny = y + dy[cur];
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;

                    string tmp = n + char(board[nx][ny] + '0');
                    if (tmp.length() == 6) {
                        s.insert(tmp);
                    } else
                        q.push({nx, ny, tmp});
                }
            }
        }

    cout << s.size() << "\n";
    return 0;
}
