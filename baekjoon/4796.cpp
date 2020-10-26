#include <iostream>
using namespace std;

int l, p, v;
int main() {
    int idx = 0;
    while (++idx) {
        cin >> l >> p >> v;
        if (!l && !p && !v) return 0;

        int cnt = 0;
        cnt += (v % p >= l) ? l : v % p;
        v /= p;
        cnt += v * l;

        cout << "Case " << idx << ": " << cnt << "\n";
    }
    return 0;
}
