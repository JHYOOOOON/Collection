#include <iostream>
using namespace std;

int main() {
    int student[1002], d[1002] = {0};
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> student[i];

    for (int i = 2; i <= n; i++) {
        int high = 0, low = 10001;
        for (int j = i; j >= 1; j--) {
            low = min(low, student[j]);
            high = max(high, student[j]);
            d[i] = max(d[i], high - low + d[j - 1]);
        }
    }
    cout << d[n] << "\n";
    return 0;
}
