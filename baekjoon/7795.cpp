#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int t, n, m;
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int j = 0; j < m; j++) cin >> b[j];

        sort(b.begin(), b.end(), greater<int>());

        int sum = 0;
        for (int n : a) {
            for (int i = 0; i < m; i++) {
                if (n > b[i]) {
                    sum += m - i;
                    break;
                }
            }
        }

        cout << sum << "\n";
    }
    return 0;
}
