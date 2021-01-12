#include <iostream>
#define MAX 5000 + 1
#define MOD 1000000007
using namespace std;

int t, n;
long long d[5001];

long long bracket(int x) {
    if (x == 0) return 1;
    if (d[x] >= 0) return d[x];

    d[x] = 0;
    for (int i = 2; i <= x; i += 2) {
        d[x] += (bracket(i - 2) * bracket(x - i));
        d[x] %= MOD;
    }

    return d[x];
}

int main() {
    fill(d, d + MAX, -1);

    cin >> t;
    while (t--) {
        cin >> n;
        (n % 2) ? cout << "0\n" : cout << bracket(n) << "\n";
    }

    return 0;
}
