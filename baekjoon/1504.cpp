#include <iostream>
#include <queue>
#include <vector>
#define INF 800001
using namespace std;
using pii = pair<int, int>;

int d[801];
vector<pair<int, int>> board[200001];
int n, e;

void reset() {
    for (int i = 1; i <= n; i++) d[i] = INF;
}

void dijkstra(int start) {
    reset();

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[start] = 0;
    pq.push({d[start], start});

    while (!pq.empty()) {
        int idx = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist != d[idx]) continue;

        for (auto v : board[idx]) {
            int nxt_idx = v.second;
            int nxt_dist = v.first;

            if (d[nxt_idx] > dist + nxt_dist) {
                d[nxt_idx] = dist + nxt_dist;
                pq.push({d[nxt_idx], nxt_idx});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;

    int a, b, c;
    while (e--) {
        cin >> a >> b >> c;
        board[a].push_back({c, b});
        board[b].push_back({c, a});
    }

    int one, two;
    cin >> one >> two;

    int result_one = 0, result_two = 0;

    dijkstra(1);
    result_one += d[one];
    result_two += d[two];

    dijkstra(one);
    result_one += d[two];
    result_two += d[two];

    dijkstra(n);
    result_one += d[two];
    result_two += d[one];

    if (result_one <= result_two) {
        result_one >= INF ? cout << "-1\n" : cout << result_one << "\n";
    } else {
        result_two >= INF ? cout << "-1\n" : cout << result_two << "\n";
    }

    return 0;
}
