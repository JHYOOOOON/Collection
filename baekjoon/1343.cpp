#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s, ans = "";
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'X') cnt++;
        if (s[i] == '.' || i == s.length() - 1) {
            if (cnt % 2 != 0) {
                cout << -1 << "\n";
                return 0;
            } else if (cnt != 0) {
                int c = cnt % 4;
                int d = c / 2;
                c = (cnt - c) / 4;
                while (c--) ans += "AAAA";
                while (d--) ans += "BB";
                cnt = 0;
            }
            if (s[i] == '.') {
                ans += ".";
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
