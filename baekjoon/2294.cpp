#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coin(n);
    for (int i = 0; i < n; i++) cin >> coin[i];

    vector<int> d(k + 1, MAX);
    d[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            if (j - coin[i] >= 0) d[j] = min(d[j], d[j - coin[i]] + 1);

    d[k] == MAX ? cout << -1 : cout << d[k];
    cout << "\n";

    return 0;
}
