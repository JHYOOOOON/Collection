#include <iostream>
using namespace std;

int main() {
    int n, f;
    cin >> n >> f;
    int tmp = n - n % 100;

    while (true) {
        if (tmp % f == 0) break;
        tmp++;
    }

    int ans = tmp % 100;
    (ans < 10) ? cout << 0 << ans << "\n" : cout << ans << "\n";
    return 0;
}
