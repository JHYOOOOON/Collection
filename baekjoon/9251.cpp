#include <iostream>
#define MAX 1000 + 2
using namespace std;

int board[MAX][MAX] = {0};
string a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;

    for (int i = 1; i <= b.length(); i++) {
        for (int j = 1; j <= a.length(); j++) {
            if (a[j - 1] == b[i - 1])
                board[i][j] = board[i - 1][j - 1] + 1;
            else
                board[i][j] = max(board[i - 1][j], board[i][j - 1]);
        }
    }

    cout << board[b.length()][a.length()] << "\n";
    return 0;
}
