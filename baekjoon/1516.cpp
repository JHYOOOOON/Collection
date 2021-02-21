#include <iostream>
#include <queue>
#include <vector>
#define MAX 500 + 1
using namespace std;

int n;
int indeg[MAX] = {0};
vector<int> graph[MAX];
int cache[MAX], time[MAX];

void check() {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0) q.push(i);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            if (--indeg[nxt] == 0) q.push(nxt);
            cache[nxt] = max(cache[nxt], cache[cur] + time[cur]);
        }
    }
}

int main() {
    cin >> n;
    int prev;
    for (int i = 1; i <= n; i++) {
        cin >> time[i];
        while (1) {
            cin >> prev;
            if (prev == -1) break;
            graph[prev].push_back(i);
            indeg[i]++;
        }
    }

    check();

    for (int i = 1; i <= n; i++) cout << cache[i] + time[i] << "\n";

    return 0;
}
