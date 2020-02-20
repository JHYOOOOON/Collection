#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, st_idx, ed_idx;
    bool flag, error;
    char x;
    string s, tmp = "";
    vector<string> v;
    cin >> t;
    while (t--)
    {
        error = false;
        flag = true;
        v.clear();
        cin >> s;
        cin >> n;
        st_idx = 0;
        ed_idx = n - 1;
        while (1)
        {
            cin >> x;
            if (x != '[' && x != ']' && x != ',')
                tmp += x;
            if (x == ',')
            {
                v.push_back(tmp);
                tmp = "";
            }
            else if (x == ']')
            {
                if (tmp != "")
                {
                    v.push_back(tmp);
                    tmp = "";
                }
                break;
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'R')
                flag ? flag = false : flag = true;
            else
            {
                flag ? st_idx++ : ed_idx--;
                if (st_idx > ed_idx + 1 || n == 0)
                {
                    error = true;
                    break;
                }
            }
        }
        if (error)
        {
            cout << "error"
                 << "\n";
        }
        else
        {
            cout << '[';
            if (st_idx > ed_idx || v.empty())
            {
                cout << ']' << "\n";
            }
            else if (flag)
            {
                for (int i = st_idx; i <= ed_idx; i++)
                {
                    cout << v[i];
                    if (i == ed_idx)
                        continue;
                    cout << ',';
                }
                cout << ']' << "\n";
            }
            else
            {
                for (int i = ed_idx; i >= st_idx; i--)
                {
                    cout << v[i];
                    if (i == st_idx)
                        continue;
                    cout << ',';
                }
                cout << ']' << "\n";
            }
        }
    }

    return 0;
}
