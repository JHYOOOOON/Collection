#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;

    if (b + c < 60)
    {
        b += c;
    }
    else
    {
        a = (a + (b + c) / 60) % 24;
        b = (b + c) % 60;
    }
    cout << a << ' ' << b << "\n";

    return 0;
}
