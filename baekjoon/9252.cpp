#include <iostream>
#define MAX 1000 + 5
using namespace std;

string a, b;
int board[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            board[i][j] = (a[i - 1] == b[j - 1])
                              ? board[i - 1][j - 1] + 1
                              : max(board[i - 1][j], board[i][j - 1]);
        }
    }

    cout << board[a.length()][b.length()] << "\n";

    int i = a.length(), j = b.length();
    string ans = "";
    while (board[i][j]) {
        if (board[i][j] == board[i - 1][j])
            i--;
        else if (board[i][j] == board[i][j - 1])
            j--;
        else {
            ans = a[i - 1] + ans;
            i--;
            j--;
        }
    }

    cout << ans << "\n";

    return 0;
}
