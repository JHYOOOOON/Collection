#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s, tmp;
    cin >> n;
    cin >> s;
    for (int i = 1; i < n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < s.length(); j++)
            if (s[j] != tmp[j])
                s[j] = '?';
    }

    cout << s << "\n";
    return 0;
}
