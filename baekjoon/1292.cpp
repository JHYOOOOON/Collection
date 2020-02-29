#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, sum = 0;
    vector<int> v;
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
        for (int j = 1; j <= i; j++)
            v.push_back(i);
    for (int i = a - 1; i <= b - 1; i++)
        sum += v[i];
    cout << sum << "\n";
    return 0;
}
