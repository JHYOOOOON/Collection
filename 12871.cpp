#include <algorithm>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
    string s, t;
    cin >> s >> t;

    if (s.length() == t.length()) {
        (s == t) ? cout << "1\n" : cout << "0\n";
    } else {
        int len = lcm(s.length(), t.length());

        string s_str, t_str;
        while (s_str.length() != len) s_str += s;
        while (t_str.length() != len) t_str += t;

        (s_str == t_str) ? cout << "1\n" : cout << "0\n";
    }

    return 0;
}
