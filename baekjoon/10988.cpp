#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    bool flag = true; // 팰린드롬이면 true 아니면 false
    cin >> s;
    int len = s.length() - 1;
    for (int i = 0; i <= len / 2; i++)
        if (s[i] != s[len - i])
        {
            flag = false;
            break;
        }
    flag ? cout << 1 << "\n" : cout << 0 << "\n";
    return 0;
}
