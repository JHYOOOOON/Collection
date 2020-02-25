#include <bits/stdc++.h>
using namespace std;

bool num[10001];
int mn = 0, sum = 0;

void squared(int m, int n)
{
    for (int i = 1; i <= sqrt(n); i++)
        num[i * i] = true;
    for (int i = m; i <= n; i++)
    {
        if (num[i])
        {
            sum += i;
            if (!mn)
                mn = i;
        }
    }
    return;
}

int main()
{
    int n, m;
    cin >> m >> n;
    squared(m, n);
    (!mn) ? cout << -1 << "\n" : cout << sum << "\n"
                                      << mn << "\n";

    return 0;
}
