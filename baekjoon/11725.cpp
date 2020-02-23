#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int n;
int parent[MAX];
bool visited[MAX];
vector<int> tree[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    queue<int> q;
    parent[1] = 0;
    visited[1] = true;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < tree[cur].size(); i++)
        {
            if (!visited[tree[cur][i]])
            {
                visited[tree[cur][i]] = 1;
                parent[tree[cur][i]] = cur;
                q.push(tree[cur][i]);
            }
        }
    }

    for (int i = 2; i <= n; i++)
        cout << parent[i] << "\n";
    return 0;
}
