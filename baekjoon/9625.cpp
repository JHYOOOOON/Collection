#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;

    int cnt[2] = {1, 0};

    while (k--) {
        int tmp[2] = {0, 0};
        tmp[1] = cnt[0];
        tmp[0] += cnt[1];
        tmp[1] += cnt[1];

        cnt[0] = tmp[0];
        cnt[1] = tmp[1];
    }

    cout << cnt[0] << ' ' << cnt[1] << "\n";

    return 0;
}
