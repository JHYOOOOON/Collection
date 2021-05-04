#include <cstring>
#include <iostream>
#include <queue>
#define MAX 10000 + 1
#define MOD 10000
#define num first
#define cmd second
using namespace std;

int t, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    bool visited[MAX];
    while (t--) {
        cin >> a >> b;
        memset(visited, 0, sizeof(visited));
        queue<pair<int, string>> q;
        visited[a] = 1;
        q.push({a, ""});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            if (cur.num == b) {
                cout << cur.cmd << "\n";
                break;
            }

            // D
            int n = (cur.num * 2) % MOD;
            if (!visited[n]) {
                visited[n] = 1;
                q.push({n, cur.cmd + 'D'});
            }

            // S
            n = (cur.num - 1 < 0) ? 9999 : cur.num - 1;
            if (!visited[n]) {
                visited[n] = 1;
                q.push({n, cur.cmd + 'S'});
            }

            // L
            n = (cur.num % 1000) * 10 + cur.num / 1000;
            if (!visited[n]) {
                visited[n] = 1;
                q.push({n, cur.cmd + 'L'});
            }

            // R
            n = (cur.num % 10) * 1000 + (cur.num / 10);
            if (!visited[n]) {
                visited[n] = 1;
                q.push({n, cur.cmd + 'R'});
            }
        }
    }
    return 0;
}
