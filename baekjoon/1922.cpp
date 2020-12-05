#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#define MAX 1000 + 5
using namespace std;
using tiii = tuple<int, int, int>;

int n, m;
vector<pair<int, int>> board[MAX];
bool check[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        board[a].push_back({c, b});
        board[b].push_back({c, a});
    }

    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    for (auto nxt : board[1]) pq.push({nxt.first, 1, nxt.second});

    check[1] = 1;

    int cnt = 0;
    int sum = 0;
    while (1) {
        int cost, v1, v2;
        tie(cost, v1, v2) = pq.top();
        pq.pop();
        if (check[v2]) continue;
        check[v2] = 1;
        cnt++;
        sum += cost;
        if (n - 1 == cnt) break;
        for (auto nxt : board[v2])
            if (!check[nxt.second]) pq.push({nxt.first, v2, nxt.second});
    }

    cout << sum << "\n";
    return 0;
}
