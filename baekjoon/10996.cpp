#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n * 2; i++)
    {
        if (i % 2 == 1)
            for (int j = 1; j <= n; j++)
                (j % 2 == 1) ? cout << '*' : cout << ' ';
        else
            for (int j = 1; j <= n; j++)
                (j % 2 == 1) ? cout << ' ' : cout << '*';
        cout << "\n";
    }
    return 0;
}
