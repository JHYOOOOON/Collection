#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pair<string, int>> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end(), compare);
        cout << v[0].first << "\n";
    }
    return 0;
}
