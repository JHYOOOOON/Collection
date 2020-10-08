#include <iostream>
#include <vector>
#define W first
#define V second
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> bag(n);
    for (int i = 0; i < n; i++) cin >> bag[i].W >> bag[i].V;

    vector<int> d(k + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = k; j >= 0; j--)
            if (j - bag[i].W >= 0) d[j] = max(d[j], d[j - bag[i].W] + bag[i].V);

    cout << d[k] << "\n";
    return 0;
}
