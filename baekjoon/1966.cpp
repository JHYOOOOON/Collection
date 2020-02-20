#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, tmp, cnt = 0;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            q.push({i, tmp});
            pq.push(tmp);
        }

        while (!q.empty())
        {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if (pq.top() == value)
            {
                pq.pop();
                cnt++;
                if (index == m)
                {
                    cout << cnt << "\n";
                    break;
                }
            }
            else
            {
                q.push({index, value});
            }
        }
    }

    return 0;
}
