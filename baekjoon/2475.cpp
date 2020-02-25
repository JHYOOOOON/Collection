#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tmp, sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> tmp;
        sum += tmp * tmp;
    }
    cout << sum % 10 << "\n";
    return 0;
}
