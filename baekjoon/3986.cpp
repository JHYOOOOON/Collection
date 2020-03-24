#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;

void compare(string tmp)
{
    stack<char> s;
    s.push(tmp[0]);
    for (int i = 1; i < tmp.length(); i++)
    {
        if (!s.empty() && s.top() == tmp[i])
            s.pop();
        else
            s.push(tmp[i]);
    }
    if (s.empty())
        cnt++;
    return;
}

int main()
{
    string tmp;
    cin >> n;
    while (n--)
    {
        cin >> tmp;
        compare(tmp);
    }
    cout << cnt << "\n";
    return 0;
}
