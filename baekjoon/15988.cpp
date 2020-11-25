#include <iostream>
#define MAX 1000000 + 1
#define MOD 1000000009
using namespace std;

int t, n;
long long d[MAX] = {0, 1, 2, 4};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 4; i < MAX; i++) {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        d[i] %= MOD;
    }

    while (t--) {
        cin >> n;
        cout << d[n] << "\n";
    }

    return 0;
}
