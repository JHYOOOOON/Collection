#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    if (a.length() < b.length()) {
        while (a.length() != b.length()) a = '0' + a;

    } else if (b.length() < a.length()) {
        while (a.length() != b.length()) b = '0' + b;
    }

    string c = "";
    int flag = 0;
    for (int i = a.length() - 1; i >= 0; i--) {
        int n = a[i] - '0' + b[i] - '0' + flag;
        if (n >= 10) {
            flag = n / 10;
            c = char(n % 10 + '0') + c;
        } else {
            flag = 0;
            c = char(n + '0') + c;
        }
    }
    if (flag) c = char(flag + '0') + c;

    cout << c << "\n";
    return 0;
}
