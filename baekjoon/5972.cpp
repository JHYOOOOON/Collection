#include <iostream>
#include <queue>
#include <vector>
#define MAX 50000 + 1
#define INF 50000000
using namespace std;

vector<pair<int, int>> road[MAX];
int d[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        road[a].push_back({c, b});
        road[b].push_back({c, a});
    }

    for (int i = 1; i <= n; i++) d[i] = INF;

    priority_queue<pair<int, int>> pq;
    d[1] = 0;
    pq.push({d[1], 1});
    while (!pq.empty()) {
        int stover = pq.top().first * -1;
        int idx = pq.top().second;
        pq.pop();
        if (stover != d[idx]) continue;

        for (auto nxt : road[idx]) {
            int nxt_stover = nxt.first;
            int nxt_idx = nxt.second;
            if (d[nxt_idx] > nxt_stover + stover) {
                d[nxt_idx] = nxt_stover + stover;
                pq.push({d[nxt_idx] * -1, nxt_idx});
            }
        }
    }

    cout << d[n] << "\n";

    return 0;
}
