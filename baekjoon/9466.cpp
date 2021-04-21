#include <algorithm>
#include <iostream>
#define MAX 100000 + 1
using namespace std;

int t, n, ans;
int board[MAX];
bool isused[MAX], done[MAX];

void dfs(int idx) {
    int nxt = board[idx];
    isused[idx] = 1;

    if (!isused[nxt])
        dfs(nxt);
    else {
        if (!done[nxt]) {
            for (int i = nxt; i != idx; i = board[i]) ans++;
            ans++;
        }
    }
    done[idx] = 1;
}

void init() {
    fill(isused, isused + n + 1, 0);
    fill(done, done + n + 1, 0);
    ans = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> board[i];
        init();

        for (int i = 1; i <= n; i++)
            if (!isused[i]) dfs(i);

        cout << n - ans << "\n";
    }

    return 0;
}
