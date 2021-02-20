#include <iostream>
#define MAX 50 + 1
using namespace std;

int n;
int board[MAX];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];

    int cnt = 0;
    bool zero, odd;
    while (1) {
        zero = true;
        odd = false;
        for (int i = 0; i < n; i++) {
            if (board[i]) zero = false;
            if (board[i] % 2) {
                odd = true;
                board[i]--;
                break;
            }
        }

        if (zero) {
            cout << cnt << "\n";
            return 0;
        }

        if (!odd)
            for (int i = 0; i < n; i++) board[i] /= 2;

        cnt++;
    }

    return 0;
}
