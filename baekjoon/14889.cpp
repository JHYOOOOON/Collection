#include <iostream>
#include <vector>
#define MAX 20 + 1
#define INF 100
using namespace std;

int n, mn = INF;
int board[MAX][MAX];
bool select[MAX];

void check(int idx, int cnt) {
    if (cnt == n / 2) {
        vector<int> start, link;
        for (int i = 0; i < n; i++)
            (select[i]) ? start.push_back(i) : link.push_back(i);

        int start_sum = 0, link_sum = 0;
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n / 2; j++) {
                start_sum += board[start[i]][start[j]];
                link_sum += board[link[i]][link[j]];
            }

        mn = min(mn, abs(start_sum - link_sum));
        return;
    }

    for (int i = idx; i < n; i++) {
        if (!select[i]) {
            select[i] = 1;
            check(i + 1, cnt + 1);
            select[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];

    check(0, 0);
    cout << mn << "\n";

    return 0;
}
