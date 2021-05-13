#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<string> ans;
bool isused[10];
char sign[10];

void check(int depth, string str) {
    if (depth == n) {
        ans.push_back(str);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (!isused[i]) {
            if ((sign[depth] == '<' && str[depth] - '0' < i) ||
                (sign[depth] == '>' && str[depth] - '0' > i)) {
                isused[i] = 1;
                check(depth + 1, str + char(i + '0'));
                isused[i] = 0;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> sign[i];

    for (int i = 0; i < 10; i++) {
        isused[i] = 1;
        check(0, to_string(i));
        isused[i] = 0;
    }

    sort(ans.begin(), ans.end());
    cout << ans[ans.size() - 1] << "\n" << ans[0] << "\n";

    return 0;
}
