#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coin(n + 1);
    for (int i = 0; i < n; i++) cin >> coin[i];

    vector<int> d(k + 1, 0);
    d[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            if (j - coin[i] >= 0) d[j] += d[j - coin[i]];

    cout << d[k] << "\n";
    return 0;
}
