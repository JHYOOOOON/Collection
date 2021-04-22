#include <iostream>
#include <queue>
#define N first
#define cnt second
#define MAX 99999 + 1
using namespace std;

int n, t, g;
bool visited[MAX];

int main() {
    cin >> n >> t >> g;

    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.cnt > t) break;
        if (cur.N == g) {
            cout << cur.cnt << "\n";
            return 0;
        }

        if (cur.N + 1 < MAX && !visited[cur.N + 1]) {
            visited[cur.N + 1] = 1;
            q.push({cur.N + 1, cur.cnt + 1});
        }

        if (cur.N * 2 < MAX) {
            string tmp = to_string(cur.N * 2);
            if (tmp != "0") tmp[0] -= 1;
            int nxt = stoi(tmp);
            if (!visited[nxt]) {
                visited[nxt] = 1;
                q.push({nxt, cur.cnt + 1});
            }
        }
    }

    cout << "ANG\n";

    return 0;
}
