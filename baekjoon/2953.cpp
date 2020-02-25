#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tmp, mx = 0, index;
    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            cin >> tmp;
            sum += tmp;
        }
        if (mx < sum)
        {
            mx = sum;
            index = i + 1;
        }
    }
    cout << index << ' ' << mx << "\n";
    return 0;
}
