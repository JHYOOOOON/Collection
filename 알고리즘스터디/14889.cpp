#include <iostream>
#include <vector>
#define MAX 20 + 1
#define INF 2000 + 5
using namespace std;

int n;
int board[MAX][MAX];
bool isused[MAX];
int mn = INF;

void confirm() {
    vector<int> start, link;
    for (int i = 0; i < n; i++)
        (isused[i]) ? start.push_back(i) : link.push_back(i);

    int start_sum = 0, link_sum = 0;
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++) {
            start_sum += board[start[i]][start[j]];
            link_sum += board[link[i]][link[j]];
        }

    if (mn > abs(start_sum - link_sum)) mn = abs(start_sum - link_sum);
}

void divTeam(int cnt, int idx) {
    if (cnt == n / 2) confirm();

    for (int i = idx; i < n; i++) {
        if (!isused[i]) {
            isused[i] = 1;
            divTeam(cnt + 1, i + 1);
            isused[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];

    divTeam(0, 0);

    cout << mn << "\n";

    return 0;
}
