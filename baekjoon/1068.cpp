#include <iostream>
#include <queue>
#include <vector>
#define MAX 50 + 1
using namespace std;

int n, rm;
int before[MAX];
bool check[MAX];

int main() {
    cin >> n;
    int root;
    for (int i = 0; i < n; i++) {
        cin >> before[i];
        if (before[i] == -1) root = i;
    }
    cin >> rm;

    if (rm == root) {
        cout << "0\n";
        return 0;
    }

    vector<vector<int>> tree(n);
    for (int i = 0; i < n; i++) {
        if (before[i] == -1) continue;
        tree[before[i]].push_back(i);
    }

    queue<int> q;
    q.push(root);
    check[root] = check[rm] = 1;

    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        bool flag = false;
        for (auto t : tree[cur]) {
            if (!check[t]) {
                flag = true;
                check[t] = 1;
                q.push(t);
            }
        }
        if (!flag) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
