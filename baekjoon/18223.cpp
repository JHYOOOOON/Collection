#include <iostream>
#include <queue>
#include <vector>
#define INF 50000000
#define MAX 5000 + 1
using namespace std;
using pii = pair<int, int>;

int d[MAX];
vector<pair<int, int>> road[MAX];

int v, e, p;

void reset() {
    for (int i = 1; i <= v; i++) d[i] = INF;
}

void dijkstra(int start) {
    reset();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[start] = 0;
    pq.push({d[start], start});

    int cnt, idx;
    while (!pq.empty()) {
        cnt = pq.top().first;
        idx = pq.top().second;
        pq.pop();

        if (d[idx] != cnt) continue;
        for (auto nxt : road[idx]) {
            int ncnt = nxt.first;
            int nidx = nxt.second;

            if (d[nidx] > ncnt + cnt) {
                d[nidx] = ncnt + cnt;
                pq.push({d[nidx], nidx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e >> p;

    int a, b, c;
    while (e--) {
        cin >> a >> b >> c;
        road[a].push_back({c, b});
        road[b].push_back({c, a});
    }

    dijkstra(1);
    int shortest = d[v];
    int k = d[p];

    dijkstra(p);
    k += d[v];

    (shortest == k) ? cout << "SAVE HIM\n" : cout << "GOOD BYE\n";

    return 0;
}
