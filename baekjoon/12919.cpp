#include <algorithm>
#include <iostream>
#define MAX 60 + 1
using namespace std;

string s, t;
bool flag = false;

void change(string a) {
    if (s.length() > a.length()) return;

    if (s == a) {
        flag = true;
        return;
    }

    if (a[a.length() - 1] == 'A') {
        change(a.substr(0, a.length() - 1));
    }
    if (a[0] == 'B') {
        reverse(a.begin(), a.end());
        a = a.substr(0, a.length() - 1);
        change(a);
    }
}

int main() {
    cin >> s >> t;
    change(t);
    (flag) ? cout << "1\n" : cout << "0\n";

    return 0;
}
