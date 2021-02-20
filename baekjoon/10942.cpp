#include <iostream>
#define MAX 2000 + 1
using namespace std;

int n, m;
int board[MAX];
bool d[MAX][MAX];

void palindrome() {
    for (int i = 1; i <= n; i++) d[i][i] = 1;
    for (int i = 1; i < n; i++)
        if (board[i] == board[i + 1]) d[i][i + 1] = 1;
    for (int i = 2; i < n; i++)
        for (int j = 1; j <= n - i; j++)
            if (board[j] == board[j + i] && d[j + 1][j + i - 1])
                d[j][j + i] = 1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &board[i]);

    cin >> m;
    palindrome();
    int a, b;
    while (m--) {
        scanf("%d %d", &a, &b);
        (d[a][b]) ? printf("1\n") : printf("0\n");
    }

    return 0;
}
