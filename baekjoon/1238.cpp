#include <iostream>
#include <queue>
#include <vector>
#define INF 10000000
#define MAX 1000 + 1
using namespace std;
using pii = pair<int, int>;

int d[MAX];
vector<pair<int, int>> road[MAX];
int cnt[MAX] = {0};

int n, m, x;

void reset() {
    for (int i = 1; i <= n; i++) d[i] = INF;
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

    cin >> n >> m >> x;

    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        road[a].push_back({c, b});
    }

    dijkstra(x);
    for (int i = 1; i <= n; i++) cnt[i] += d[i];
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        cnt[i] += d[x];
    }

    int mx = 0;
    for (int i = 1; i <= n; i++)
        if (mx < cnt[i]) mx = cnt[i];

    cout << mx << "\n";

    return 0;
}
