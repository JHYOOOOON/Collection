#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int b, c;
    cin >> b >> c;

    long cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt++;
        v[i] -= b;
        if (v[i] > 0) {
            cnt += v[i] / c;
            if (v[i] % c) cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
