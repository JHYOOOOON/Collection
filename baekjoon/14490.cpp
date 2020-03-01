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

int main()
{
    int a, b;
    scanf("%d:%d", &a, &b);
    int c = gcd(a, b);
    printf("%d:%d", a / c, b / c);
    return 0;
}
