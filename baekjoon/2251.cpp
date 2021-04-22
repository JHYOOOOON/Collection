#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#define MAX 200 + 1
using namespace std;

int a, b, c;
vector<int> check;
bool visited[MAX][MAX][MAX];

void bfs() {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, c});

    int x, y, z;
    while (!q.empty()) {
        tie(x, y, z) = q.front();
        q.pop();

        if (visited[x][y][z]) continue;
        visited[x][y][z] = 1;

        if (x == 0) {
            check.push_back(z);
        }

        if (x + y > b)
            q.push({x + y - b, b, z});
        else
            q.push({0, x + y, z});

        if (x + z > c)
            q.push({x + y - c, y, c});
        else
            q.push({0, y, x + z});

        if (y + x > a)
            q.push({a, y + x - a, z});
        else
            q.push({y + x, 0, z});

        if (y + z > c)
            q.push({x, y + z - c, c});
        else
            q.push({x, 0, y + z});

        if (z + x > a)
            q.push({a, y, z + x - a});
        else
            q.push({z + x, y, 0});

        if (z + y > b)
            q.push({x, b, z + y - b});
        else
            q.push({x, z + y, 0});
    }
    return;
}

int main() {
    cin >> a >> b >> c;
    bfs();

    sort(check.begin(), check.end());
    for (int num : check) cout << num << ' ';
    cout << "\n";

    return 0;
}
