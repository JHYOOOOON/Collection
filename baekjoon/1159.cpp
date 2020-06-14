#include <iostream>
using namespace std;

int main() {
    int alpha[30] = {
        0,
    };
    int n;
    string s;
    cin >> n;

    while (n--) {
        cin >> s;
        alpha[s[0] - 'a']++;
    }

    bool flag = false;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] >= 5) {
            cout << char('a' + i);
            flag = true;
        }
    }

    if (!flag) cout << "PREDAJA\n";

    return 0;
}
