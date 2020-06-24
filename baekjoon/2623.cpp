#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int k, a;
    vector<int> board[n + 1];
    vector<int> indeg(n + 1, 0);
    while (m--) {
        int tmp = 0;
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> a;
            if (tmp) {
                board[tmp].push_back(a);
                indeg[a]++;
            }
            tmp = a;
        }
    }

    queue<int> q;
    vector<int> result;
    for (int i = 1; i <= n; i++)
        if (!indeg[i]) q.push(i);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for (int i = 0; i < board[cur].size(); i++) {
            int nxt = board[cur][i];
            indeg[nxt]--;
            if (!indeg[nxt]) q.push(nxt);
        }
    }
    if (result.size() != n) {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < result.size(); i++) cout << result[i] << "\n";
    return 0;
}
