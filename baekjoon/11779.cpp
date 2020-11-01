#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000 + 1
#define INF 100000000
using namespace std;
using pii = pair<int, int>;

int n, m;

int d[MAX];
vector<pair<int, int>> city[MAX];
int before[MAX];

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[start] = 0;
    before[start] = 0;
    pq.push({d[start], start});

    int cost, idx;
    while (!pq.empty()) {
        cost = pq.top().first;
        idx = pq.top().second;
        pq.pop();

        if (d[idx] != cost) continue;
        for (auto nxt : city[idx]) {
            int ncost = nxt.first;
            int nidx = nxt.second;
            if (d[nidx] > ncost + cost) {
                d[nidx] = ncost + cost;
                pq.push({d[nidx], nidx});
                before[nidx] = idx;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        city[a].push_back({c, b});
    }

    int start, arrive;
    cin >> start >> arrive;

    for (int i = 1; i <= n; i++) d[i] = INF;

    dijkstra(start);

    vector<int> road;

    int idx = arrive;
    while (idx) {
        road.push_back(idx);
        idx = before[idx];
    }

    cout << d[arrive] << "\n" << road.size() << "\n";
    for (int i = road.size() - 1; i >= 0; i--) cout << road[i] << ' ';

    return 0;
}
