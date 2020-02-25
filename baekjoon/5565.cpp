#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum, tmp;
    cin >> sum;
    for (int i = 0; i < 9; i++)
    {
        cin >> tmp;
        sum -= tmp;
    }
    cout << sum << "\n";
    return 0;
}
