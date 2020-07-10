#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int mx = -1000000000;
int mn = 1000000000;
int n, num[15], cal[4];

void caculator(int depth, int plus, int minus, int multi, int div, int total) {
    if (depth == n) {
        if (mx < total) mx = total;
        if (mn > total) mn = total;
        return;
    }

    if (plus < cal[0])
        caculator(depth + 1, plus + 1, minus, multi, div, total + num[depth]);
    if (minus < cal[1])
        caculator(depth + 1, plus, minus + 1, multi, div, total - num[depth]);
    if (multi < cal[2])
        caculator(depth + 1, plus, minus, multi + 1, div, total * num[depth]);
    if (div < cal[3])
        caculator(depth + 1, plus, minus, multi, div + 1, total / num[depth]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    for (int i = 0; i < 4; i++) cin >> cal[i];
    caculator(1, 0, 0, 0, 0, num[0]);
    cout << mx << "\n" << mn << "\n";
    return 0;
}
