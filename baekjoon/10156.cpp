#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, n, m, ans;
    cin >> k >> n >> m;
    (k * n - m < 0) ? cout << 0 << "\n" : cout << k * n - m << "\n";
    return 0;
}
