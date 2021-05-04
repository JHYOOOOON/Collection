#include <iostream>
using namespace std;

int n, m, ans, len;
bool broken[10] = {false};

void check(int x) {
    if (x == 0) {
        if (broken[x])
            return;
        else
            ans = min(ans, n + 1);
    } else {
        int length = abs(x - n);

        while (x > 0) {
            length++;
            if (broken[x % 10]) return;
            x /= 10;
        }

        ans = min(ans, length);
    }
}

int main() {
    cin >> n >> m;

    int btn;
    for (int i = 0; i < m; i++) {
        cin >> btn;
        broken[btn] = 1;
    }

    ans = abs(n - 100);
    int start = (n - ans <= 0) ? 0 : n - ans;
    int end = n + ans;

    for (int i = start; i <= end; i++) check(i);

    cout << ans << "\n";

    return 0;
}
