#include <bits/stdc++.h>
using namespace std;

int main()
{
    // tall: 9개 키 배열, sum: 9개 키 합, idx: 난쟁이가 아닌 tall 인덱스
    int tall[9], sum = 0, idx[2];
    for (int i = 0; i < 9; i++)
    {
        cin >> tall[i];
        sum += tall[i];
    }

    // tall 오름차순 정렬
    sort(tall, tall + 9);

    // 두 키값을 뺐을 때 100이 되면 두 키값을 idx에 저장
    for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 9; j++)
            if (sum - tall[i] - tall[j] == 100)
            {
                idx[0] = i;
                idx[1] = j;
                break;
            }

    // 출력
    for (int i = 0; i < 9; i++)
    {
        if (i == idx[0] || i == idx[1])
            continue;
        cout << tall[i] << "\n";
    }

    return 0;
}
