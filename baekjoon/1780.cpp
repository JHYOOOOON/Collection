#include <iostream>
using namespace std;

int board[2200][2200];
int zero = 0, one = 0, m_one = 0;

void paper(int x, int y, int n) {
    int cnt = 0, m_cnt = 0;
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (board[i][j] == 1)
                cnt++;
            else if (board[i][j] == -1)
                m_cnt++;
    if (!m_cnt && !cnt)
        zero++;
    else if (m_cnt == n * n)
        m_one++;
    else if (cnt == n * n)
        one++;
    else {
        paper(x, y, n / 3);
        paper(x + n / 3, y, n / 3);
        paper(x + n * 2 / 3, y, n / 3);
        paper(x, y + n / 3, n / 3);
        paper(x + n / 3, y + n / 3, n / 3);
        paper(x + n * 2 / 3, y + n / 3, n / 3);
        paper(x, y + n * 2 / 3, n / 3);
        paper(x + n / 3, y + n * 2 / 3, n / 3);
        paper(x + n * 2 / 3, y + n * 2 / 3, n / 3);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];
    paper(0, 0, n);
    cout << m_one << "\n" << zero << "\n" << one << "\n";
    return 0;
}
