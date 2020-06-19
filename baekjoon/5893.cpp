#include <iostream>
using namespace std;

int main() {
    string b;
    cin >> b;

    string a = b;
    for (int i = 0; i < 4; i++) {
        b += '0';
        a = '0' + a;
    }

    bool c = 0;
    string ans = "";
    for (int i = a.length() - 1; i >= 0; i--) {
        if (a[i] == b[i] && a[i] == '1') {
            ans = c ? '1' + ans : '0' + ans;
            c = 1;
        } else if (a[i] == b[i] && a[i] == '0') {
            ans = c ? '1' + ans : '0' + ans;
            c = 0;
        } else {
            if (c) {
                ans = '0' + ans;
                c = 1;
            } else {
                ans = '1' + ans;
                c = 0;
            }
        }
    }
    if (c) ans = '1' + ans;

    cout << ans << "\n";
    return 0;
}
