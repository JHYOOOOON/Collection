#include <iostream>
#include <vector>
#define MAX 2000 + 5
using namespace std;

int n, m;
bool visited[MAX];
vector<int> board[MAX];
bool answer = false;

void check(int count, int before) {
    if (count == 4) {
        answer = true;
        return;
    }

    if (answer) return;

    for (int fri : board[before]) {
        if (!visited[fri]) {
            visited[fri] = 1;
            check(count + 1, fri);
            visited[fri] = 0;
        }
    }
    return;
}

int main() {
    cin >> n >> m;

    int a, b;
    while (m--) {
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            check(0, i);
            visited[i] = 0;
        }
    }

    cout << answer << "\n";

    return 0;
}
