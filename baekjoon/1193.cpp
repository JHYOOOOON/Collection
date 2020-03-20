#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int x, cnt = 0;
    cin >> x;
    while (x > 0)
    {
        cnt++;
        x -= cnt;
    }
    if (!cnt % 2)
        cout << cnt + x << '/' << 1 - x;
    else
        cout << 1 - x << '/' << cnt + x;
    return 0;
}
