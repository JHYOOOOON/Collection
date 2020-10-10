#include <iostream>
#include <vector>
#define MAX 100005
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> board(n);
    for (int i = 0; i < n; i++) cin >> board[i];

    int len = MAX;
    int sum = board[0];
    int left = 0;
    int right = 0;
    while (left <= right && right < n) {
        if (sum > s) {
            if (right - left + 1 < len) len = right - left + 1;
            sum -= board[left++];
        } else if (sum == s) {
            if (right - left + 1 < len) len = right - left + 1;
            sum += board[++right];
        } else {
            sum += board[++right];
        }
    }

    (len == MAX) ? cout << 0 : cout << len;
    return 0;
}
