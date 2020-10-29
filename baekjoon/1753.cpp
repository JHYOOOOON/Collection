#include <iostream>
#include <queue>
#include <vector>
#define MAX 987654321
using namespace std;
using pii = pair<int, int>;

vector<pair<int, int>> board[20001];
int d[200001];

int main() {
    int V, E, start;
    cin >> V >> E >> start;

    for (int i = 1; i <= V; i++) d[i] = MAX;

    int u, v, w;
    while (E--) {
        cin >> u >> v >> w;
        board[u].push_back({w, v});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[start] = 0;
    pq.push({d[start], start});
    while (!pq.empty()) {
        int idx = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist != d[idx]) continue;
        for (auto a : board[idx]) {
            int nxt_idx = a.second, nxt_dist = a.first;
            if (d[nxt_idx] > dist + nxt_dist) {
                d[nxt_idx] = dist + nxt_dist;
                pq.push({d[nxt_idx], nxt_idx});
            }
        }
    }

    for (int i = 1; i <= V; i++)
        (d[i] == MAX) ? cout << "INF\n" : cout << d[i] << "\n";

    return 0;
}
