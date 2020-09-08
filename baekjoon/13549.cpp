#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int n, k;
bool visited[MAX];

int main() {
    cin >> n >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    visited[n] = 1;
    q.push({0, n});
    while (!q.empty()) {
        int time = q.top().first;
        int idx = q.top().second;
        q.pop();

        if (idx == k) {
            cout << time << "\n";
            return 0;
        }

        if (idx * 2 < MAX && !visited[idx * 2]) {
            visited[idx * 2] = 1;
            q.push({time, idx * 2});
        }

        if (idx + 1 < MAX && !visited[idx + 1]) {
            visited[idx + 1] = 1;
            q.push({time + 1, idx + 1});
        }

        if (idx - 1 >= 0 && !visited[idx - 1]) {
            visited[idx - 1] = 1;
            q.push({time + 1, idx - 1});
        }
    }

    return 0;
}
