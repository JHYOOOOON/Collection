#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#define MAX 10000 + 5
using namespace std;
using tiii = tuple<int, int, int>;

int v, e;
vector<pair<int, int>> board[MAX];
bool check[MAX];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    int a, b, c;
    while (e--) {
        cin >> a >> b >> c;
        board[a].push_back({c, b});
        board[b].push_back({c, a});
    }

    int cnt = 0, sum = 0;
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    for (auto nxt : board[1]) pq.push({nxt.first, 1, nxt.second});
    check[1] = 1;

    while (1) {
        int cost, v1, v2;
        tie(cost, v1, v2) = pq.top();
        pq.pop();
        if (check[v2]) continue;
        check[v2] = 1;
        sum += cost;
        cnt++;
        if (cnt == v - 1) break;
        for (auto nxt : board[v2])
            if (!check[nxt.second]) pq.push({nxt.first, v2, nxt.second});
    }

    cout << sum << "\n";
    return 0;
}
