#include <bits/stdc++.h>
using namespace std;

int n, k;
bool arr[1001];

int sosu()
{
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i])
            continue;
        for (int j = i; j <= n; j += i)
        {
            if (arr[j])
                continue;
            arr[j] = true;
            cnt++;
            if (cnt == k)
                return j;
        }
    }
}

int main()
{
    cin >> n >> k;
    cout << sosu() << "\n";
    return 0;
}
