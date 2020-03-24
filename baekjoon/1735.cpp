#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int a, b, c, d, e, f;
    int multi, div;
    cin >> a >> b >> c >> d;
    multi = lcm(b, d);
    a *= (multi / b);
    c *= (multi / d);
    e = a + c;
    f = multi;
    div = gcd(e, f);
    cout << e / div << ' ' << f / div << "\n";
    return 0;
}
