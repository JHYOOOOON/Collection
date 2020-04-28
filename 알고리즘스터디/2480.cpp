#include <bits/stdc++.h>
using namespace std;

int main()
{
    int dice[3];
    cin >> dice[0] >> dice[1] >> dice[2];

    sort(dice, dice + 3);

    if (dice[0] == dice[1] && dice[1] == dice[2])
        cout << 10000 + dice[0] * 1000 << "\n";
    else if (dice[0] == dice[1] || dice[1] == dice[2])
        cout << 1000 + dice[1] * 100 << "\n";
    else
        cout << dice[2] * 100 << "\n";

    return 0;
}
