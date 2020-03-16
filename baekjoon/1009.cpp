#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        int tmp = a;
        b -= 1;
        while (b--)
        {
            a *= tmp;
            a %= 10;
        }
        if (a == 0)
            cout << 10 << "\n";
        else
            cout << a << "\n";
    }
    return 0;
}
