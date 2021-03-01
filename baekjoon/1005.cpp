#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000 + 5
using namespace std;

int t, n, k, x, y, w;
int time[MAX], d[MAX], indeg[MAX] = {0};
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        memset(d, 0, sizeof(d));
        memset(indeg, 0, sizeof(indeg));
        vector<int> adj[MAX];
        for (int i = 1; i <= n; i++) cin >> time[i];
        while (k--) {
            cin >> x >> y;
            adj[x].push_back(y);
            indeg[y]++;
        }
        cin >> w;

        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (indeg[i] == 0) {
                q.push(i);
                d[i] = time[i];
            }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nxt : adj[cur]) {
                indeg[nxt]--;
                d[nxt] = max(d[nxt], d[cur] + time[nxt]);

                if (indeg[nxt] == 0) q.push(nxt);
            }
        }

        cout << d[w] << "\n";
    }
    return 0;
}
