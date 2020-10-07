#include <cmath>
#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> d(n + 1, MAX);
    d[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j * j <= i; j++)
            if (i - j * j >= 0) d[i] = min(d[i], d[i - j * j] + 1);

    cout << d[n] << "\n";
    return 0;
}
