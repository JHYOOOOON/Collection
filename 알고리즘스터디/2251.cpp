#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#define MAX 200 + 1
using namespace std;

int A, B, C;
int visited[MAX][MAX][MAX];
vector<int> ans;

int main() {
    cin >> A >> B >> C;

    int a, b, c;
    queue<tuple<int, int, int>> q;
    visited[0][0][C] = 1;
    q.push({0, 0, C});

    while (!q.empty()) {
        tie(a, b, c) = q.front();
        q.pop();

        if (a == 0) ans.push_back(c);

        // A -> B
        if (a + b > B) {
            if (!visited[a - B + b][B][c]) {
                visited[a - B + b][B][c] = 1;
                q.push({a - B + b, B, c});
            }
        } else {
            if (!visited[0][a + b][c]) {
                visited[0][a + b][c] = 1;
                q.push({0, a + b, c});
            }
        }

        // A -> C
        if (a + c > C) {
            if (!visited[a - C + c][b][C]) {
                visited[a - C + c][b][C] = 1;
                q.push({a - C + c, b, C});
            }
        } else {
            if (!visited[0][b][a + c]) {
                visited[0][b][a + c] = 1;
                q.push({0, b, a + c});
            }
        }

        // B -> C
        if (b + c > C) {
            if (!visited[a][b - C + c][C]) {
                visited[a][b - C + c][C] = 1;
                q.push({a, b - C + c, C});
            }
        } else {
            if (!visited[a][0][b + c]) {
                visited[a][0][b + c] = 1;
                q.push({a, 0, b + c});
            }
        }

        // B -> A
        if (b + a > A) {
            if (!visited[A][b - A + a][c]) {
                visited[A][b - A + a][c] = 1;
                q.push({A, b - A + a, c});
            }
        } else {
            if (!visited[b + a][0][c]) {
                visited[b + a][0][c] = 1;
                q.push({b + a, 0, c});
            }
        }

        // C -> A
        if (c + a > A) {
            if (!visited[A][b][c - A + a]) {
                visited[A][b][c - A + a] = 1;
                q.push({A, b, c - A + a});
            }
        } else {
            if (!visited[c + a][b][0]) {
                visited[c + a][b][0] = 1;
                q.push({c + a, b, 0});
            }
        }

        // C -> B
        if (c + b > B) {
            if (!visited[a][B][c - B + b]) {
                visited[a][B][c - B + b] = 1;
                q.push({a, B, c - B + b});
            }
        } else {
            if (!visited[a][b + c][0]) {
                visited[a][b + c][0] = 1;
                q.push({a, b + c, 0});
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (int a : ans) cout << a << ' ';

    return 0;
}
