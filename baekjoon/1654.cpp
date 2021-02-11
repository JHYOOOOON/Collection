#include <iostream>
#include <vector>
using namespace std;

long long k, n;

int main() {
    cin >> k >> n;

    vector<long long> lan(k);
    long long left = 1, right = 0;
    for (int i = 0; i < k; i++) {
        cin >> lan[i];
        right = max(right, lan[i]);
    }

    long long ans = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 0; i < k; i++) cnt += lan[i] / mid;
        if (cnt >= n) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
