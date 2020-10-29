#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 987654321
using namespace std;

using pii = pair<int, int>;

int d[1001];
vector<pair<int, int>> bus[100001];
int n, m;

void calculate(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[start] = 0;
    pq.push({d[start], start});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (d[cur] < dist) continue;

        for (int i = 0; i < bus[cur].size(); i++) {
            int nxt = bus[cur][i].first;
            int nxt_dist = dist + bus[cur][i].second;

            if (nxt_dist < d[nxt]) {
                d[nxt] = nxt_dist;
                pq.push({nxt_dist, nxt});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) d[i] = MAX;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        bus[u].push_back({v, w});
    }

    int start, arrive;
    cin >> start >> arrive;

    calculate(start);

    cout << d[arrive] << "\n";
    return 0;
}
