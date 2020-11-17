#include <iostream>
#include <queue>
#define MAX 100000 + 1
using namespace std;

int n, k;
int cnt = 0;
int time = 0;
bool visited[MAX];

int main() {
    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int t = q.front().second;
        q.pop();

        visited[x] = 1;

        if (time && t == time && x == k) cnt++;

        if (!time && x == k) {
            time = t;
            cnt++;
        }

        if (x + 1 < MAX && !visited[x + 1]) q.push({x + 1, t + 1});
        if (x - 1 >= 0 && !visited[x - 1]) q.push({x - 1, t + 1});
        if (x * 2 < MAX && !visited[x * 2]) q.push({x * 2, t + 1});
    }

    cout << time << "\n" << cnt << "\n";
    return 0;
}
