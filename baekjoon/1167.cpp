#include <iostream>
#include <queue>
#include <vector>
#define MAX 100000 + 5
using namespace std;

int v;
vector<pair<int, int>> board[MAX];
bool visited[MAX];
int cost = 0;
int farthest;

void bfs(int node, int weight) {
    queue<pair<int, int>> q;
    visited[node] = 1;
    q.push({node, weight});

    int n, w;
    while (!q.empty()) {
        n = q.front().first;
        w = q.front().second;
        q.pop();

        if (board[n].size() == 1) {
            if (cost < w) {
                farthest = n;
                cost = w;
            }
            continue;
        }

        for (auto nxt : board[n]) {
            if (!visited[nxt.first]) {
                visited[nxt.first] = 1;
                q.push({nxt.first, nxt.second + w});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v;

    int parent, child, weight;
    for (int i = 0; i < v; i++) {
        cin >> parent;
        while (1) {
            cin >> child;
            if (child == -1) break;

            cin >> weight;
            board[parent].push_back({child, weight});
        }
    }

    visited[1] = 1;
    for (auto nxt : board[1]) bfs(nxt.first, nxt.second);

    fill(visited, visited + v + 1, 0);
    cost = 0;
    visited[farthest] = 1;
    bfs(board[farthest][0].first, board[farthest][0].second);

    cout << cost << "\n";

    return 0;
}
