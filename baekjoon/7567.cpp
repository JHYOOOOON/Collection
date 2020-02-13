#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int height = 10;
    cin >> s;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] != s[i - 1])
        {
            height += 10;
        }
        else
        {
            height += 5;
        }
    }

    cout << height << "\n";

    return 0;
}
