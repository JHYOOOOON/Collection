#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, w, h, cnt;
    cin >> n >> w >> h;
    while (n--)
    {
        cin >> cnt;
        (cnt * cnt <= w * w + h * h) ? cout << "DA"
                                            << "\n"
                                     : cout << "NE"
                                            << "\n";
    }
    return 0;
}
