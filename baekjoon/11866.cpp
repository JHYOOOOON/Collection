#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    vector<int> v;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    while (!dq.empty())
    {
        for (int i = 1; i < k; i++)
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        v.push_back(dq.front());
        dq.pop_front();
    }

    cout << '<';
    for (int i = 0; i < n; i++)
    {
        cout << v[i];
        if (i == n - 1)
            continue;
        cout << ", ";
    }
    cout << '>' << "\n";
    return 0;
}
