#include <bits/stdc++.h>
using namespace std;

bool arr[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, cnt = 0;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        for (int i = a; i < a + 10; i++)
            for (int j = b; j < b + 10; j++)
                arr[i][j] = true;
    }

    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            if (arr[i][j])
                cnt++;

    cout << cnt << "\n";

    return 0;
}
