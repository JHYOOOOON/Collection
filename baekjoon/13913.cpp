#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int before[MAX];
bool visited[MAX];
vector<int> tmp;

int main() {
    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = 1;

    int idx, time;
    while (!q.empty()) {
        idx = q.front().first;
        time = q.front().second;
        q.pop();

        if (idx == k) {
            cout << time << "\n";
            while (idx != n) {
                tmp.push_back(idx);
                idx = before[idx];
                if (idx == n) break;
            }
            tmp.push_back(n);

            break;
        }

        if (idx - 1 >= 0 && !visited[idx - 1]) {
            q.push({idx - 1, time + 1});

            before[idx - 1] = idx;
            visited[idx - 1] = true;
        }
        if (idx + 1 < MAX && !visited[idx + 1]) {
            q.push({idx + 1, time + 1});
            before[idx + 1] = idx;
            visited[idx + 1] = true;
        }
        if (idx * 2 < MAX && !visited[idx * 2]) {
            q.push({idx * 2, time + 1});
            before[idx * 2] = idx;
            visited[idx * 2] = true;
        }
    }

    for (int i = tmp.size() - 1; i >= 0; i--) cout << tmp[i] << ' ';
    return 0;
}
