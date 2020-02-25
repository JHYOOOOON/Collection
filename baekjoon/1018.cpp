#include <bits/stdc++.h>
using namespace std;

string white[8] = {
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"}};

string black[8] = {
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"}};

string board[51];

int blackfirst(int a, int b)
{
    int cnt = 0;
    for (int i = a; i < a + 8; i++)
        for (int j = b; j < b + 8; j++)
            if (board[i][j] != black[i - a][j - b])
                cnt++;
    return cnt;
}

int whitefirst(int a, int b)
{
    int cnt = 0;
    for (int i = a; i < a + 8; i++)
        for (int j = b; j < b + 8; j++)
            if (board[i][j] != white[i - a][j - b])
                cnt++;
    return cnt;
}

int main()
{
    int n, m, ans = 250;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];

    for (int i = 0; i + 7 < n; i++)
        for (int j = 0; j + 7 < m; j++)
            ans = min(ans, min(blackfirst(i, j), whitefirst(i, j)));

    cout << ans << "\n";

    return 0;
}
