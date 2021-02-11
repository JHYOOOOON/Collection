#include <iostream>
#define MAX 2000000 + 1
using namespace std;

int n;
int board[21];
bool isused[MAX];

void check(int depth, int sum) {
    if (depth == n) {
        isused[sum] = 1;
        return;
    }

    check(depth + 1, sum);
    check(depth + 1, sum + board[depth]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];

    check(0, 0);

    for (int i = 1; i < MAX; i++)
        if (!isused[i]) {
            cout << i << "\n";
            return 0;
        }

    return 0;
}
