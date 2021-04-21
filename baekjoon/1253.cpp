#include <algorithm>
#include <iostream>
#define MAX 2000 + 1
using namespace std;

int n;
int board[MAX];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];

    sort(board, board + n);
    int ans = 0;
    int left, right, sum;
    for (int i = 0; i < n; i++) {
        left = 0, right = n - 1;
        if (i == 0) left = 1;
        if (i == n - 1) right = n - 2;
        while (left < right) {
            sum = board[left] + board[right];
            if (sum == board[i]) {
                ans++;
                break;
            }
            (sum < board[i]) ? left++ : right--;
            if (left == i) left++;
            if (right == i) right--;
        }
    }

    cout << ans << "\n";

    return 0;
}
