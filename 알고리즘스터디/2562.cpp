#include <bits/stdc++.h>
using namespace std;

int main()
{
    // mx: 최댓값, idx: 최댓값의 순서
    int mx = 0, idx = 0, tmp;
    for (int i = 0; i < 9; i++)
    {
        cin >> tmp;
        if (tmp > mx)
        {
            mx = tmp;
            idx = i + 1;
        }
    }
    cout << mx << "\n"
         << idx;

    return 0;
}
