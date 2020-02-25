#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    priority_queue<int, vector<int>, greater<int>> q;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (!x)
        {
            if (q.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else
        {
            q.push(x);
        }
    }
    return 0;
}
