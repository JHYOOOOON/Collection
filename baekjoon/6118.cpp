#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a, b;
    vector<int> board[n + 1];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }

    queue<int> q;
    vector<int> visited(n + 1, -1);
    int mx = 0;
    visited[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < board[cur].size(); i++) {
            if (visited[board[cur][i]] != -1) continue;
            visited[board[cur][i]] = visited[cur] + 1;
            q.push(board[cur][i]);
            if (mx < visited[board[cur][i]]) mx = visited[board[cur][i]];
        }
    }

    int idx = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == mx) {
            if (idx == 0) idx = i;
            cnt++;
        }
    }
    cout << idx << ' ' << mx << ' ' << cnt << "\n";
    return 0;
}
