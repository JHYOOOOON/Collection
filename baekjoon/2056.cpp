#include <iostream>
#include <queue>
#include <vector>
#define MAX 10000 + 1
using namespace std;

int n;
vector<int> graph[MAX];
int indeg[MAX] = {0};
int time[MAX];
int cache[MAX];

int check() {
    int ans = 0;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
            cache[i] = time[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            if (--indeg[nxt] == 0) q.push(nxt);
            cache[nxt] = max(cache[nxt], cache[cur] + time[nxt]);
        }
    }

    for (int i = 1; i <= n; i++) ans = max(ans, cache[i]);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int before, m;
    for (int i = 1; i <= n; i++) {
        cin >> time[i] >> m;
        for (int j = 0; j < m; j++) {
            cin >> before;
            graph[before].push_back(i);
            indeg[i]++;
        }
    }

    cout << check() << "\n";

    return 0;
}
