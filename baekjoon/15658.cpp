#include <iostream>
#define MAX 1000000000
#define MIN -1000000000
using namespace std;

int n, v[15];
int mx = MIN, mn = MAX;

void cnt(int depth, int plus, int minus, int multi, int div, long long total) {
    if (depth == n) {
        mx = (mx < total) ? total : mx;
        mn = (mn > total) ? total : mn;
        return;
    }

    if (plus) cnt(depth + 1, plus - 1, minus, multi, div, total + v[depth]);
    if (minus) cnt(depth + 1, plus, minus - 1, multi, div, total - v[depth]);
    if (multi) cnt(depth + 1, plus, minus, multi - 1, div, total * v[depth]);
    if (div) cnt(depth + 1, plus, minus, multi, div - 1, total / v[depth]);
}

int main() {
    int m[4];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < 4; i++) cin >> m[i];

    cnt(1, m[0], m[1], m[2], m[3], v[0]);
    cout << mx << "\n" << mn << "\n";
    return 0;
}
