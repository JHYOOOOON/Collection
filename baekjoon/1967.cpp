#include <iostream>
#include <queue>
#include <vector>
#define MAX 10000 + 1
using namespace std;

int n;
vector<pair<int, int>> board[MAX];
bool visited[MAX];
int cost = 0;

void bfs(int node, int weight) {
    queue<pair<int, int>> q;
    q.push({node, weight});
    visited[node] = 1;

    int x, y;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (board[x].size() == 1) {
            cost = max(cost, y);
            continue;
        }

        for (auto nxt : board[x]) {
            if (!visited[nxt.first]) {
                q.push({nxt.first, y + nxt.second});
                visited[nxt.first] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int parent, child, weight;
    for (int i = 1; i < n; i++) {
        cin >> parent >> child >> weight;
        board[parent].push_back({child, weight});
        board[child].push_back({parent, weight});
    }

    for (int i = 1; i <= n; i++) {
        if (board[i].size() == 1) {
            fill(visited, visited + n + 1, 0);
            visited[i] = 1;
            bfs(board[i][0].first, board[i][0].second);
        }
    }

    cout << cost << "\n";

    return 0;
}
