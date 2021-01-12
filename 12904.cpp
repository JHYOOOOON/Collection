#include <algorithm>
#include <iostream>
using namespace std;

bool flag;
string s, t;

int main() {
    cin >> s >> t;

    while (1) {
        if (s.length() == t.length()) {
            if (s == t) flag = 1;
            break;
        }
        char c = t[t.length() - 1];
        t.pop_back();
        if (c == 'B') reverse(t.begin(), t.end());
    }

    cout << flag << "\n";
    return 0;
}
