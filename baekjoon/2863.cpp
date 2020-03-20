#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d, mx = 0, cnt;
    cin >> a >> b >> c >> d;
    if (a / d + b / c > mx)
    {
        mx = a / d + b / c;
        cnt = 0;
    }
    if (c / b + a / d > mx)
    {
        mx = c / b + a / d;
        cnt = 1;
    }
    if (d / a + c / b > mx)
    {
        mx = d / a + c / b;
        cnt = 2;
    }
    if (b / c + d / a > mx)
    {
        mx = b / c + d / a;
        cnt = 3;
    }
    cout << cnt << "\n";
}
