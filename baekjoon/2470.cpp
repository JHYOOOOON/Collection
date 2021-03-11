#include <algorithm>
#include <iostream>
#define MAX 100000 + 1
#define INF 2000000000
using namespace std;

int n;
int liquid[MAX];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> liquid[i];

    sort(liquid, liquid + n);

    int left = 0, right = n - 1, mix, mn = INF, x, y;
    while (left < right) {
        mix = liquid[left] + liquid[right];
        if (mn > abs(mix)) {
            mn = abs(mix);
            x = liquid[left];
            y = liquid[right];
        }
        if (mix == 0) break;
        (mix < 0) ? left++ : right--;
    }

    cout << x << ' ' << y << "\n";

    return 0;
}
