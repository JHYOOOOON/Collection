#include <iostream>
#include <vector>
#define MAX 1000 + 1
using namespace std;

int n;
int board[MAX], d[MAX];
int before[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) cin >> board[i];
    for (int i = 0; i < n; i++) before[i] = -1;

    d[0] = 1;
    for (int i = 1; i < n; i++) {
        d[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (board[j] < board[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                before[i] = j;
            }
        }
    }

    int mx = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (mx < d[i]) {
            mx = d[i];
            idx = i;
        }
    }

    cout << mx << "\n";
    vector<int> v;
    while (idx != -1) {
        v.push_back(board[idx]);
        idx = before[idx];
    }
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << ' ';

    return 0;
}
