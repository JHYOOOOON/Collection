#include <bits/stdc++.h>
using namespace std;

int main()
{
    // T: 테스트케이스, tmp: 배, 등 받는 변수
    int T = 3, tmp;
    // 모, 도, 개, 걸, 윷 순서
    char game[5] = {'E', 'A', 'B', 'C', 'D'};

    while (T--)
    {
        // 0 개수 세는 변수
        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> tmp;
            if (!tmp)
                cnt++;
        }
        cout << game[cnt] << "\n";
    }

    return 0;
}
