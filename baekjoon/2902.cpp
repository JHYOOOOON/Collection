#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (s[i] <= 'Z' && s[i] >= 'A')
            cout << s[i];
    return 0;
}
