#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 10
using namespace std;

int k;
char board[MAX];
bool isused[MAX];
vector<string> num;

void select(int depth, string tmp) {
    if (depth == k) {
        num.push_back(tmp);
        return;
    }

    for (int i = 0; i < MAX; i++) {
        if (!isused[i]) {
            if ((board[depth] == '<' && tmp[tmp.length() - 1] - '0' < i) ||
                (board[depth] == '>' && tmp[tmp.length() - 1] - '0' > i)) {
                isused[i] = 1;
                select(depth + 1, tmp + char(i + '0'));
                isused[i] = 0;
            }
        }
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) cin >> board[i];

    for (int i = 0; i < MAX; i++) {
        isused[i] = 1;
        select(0, to_string(i));
        isused[i] = 0;
    }

    sort(num.begin(), num.end());

    cout << num[num.size() - 1] << "\n" << num[0] << "\n";
    return 0;
}
