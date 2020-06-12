#include <iostream>
using namespace std;

int main() {
    string s;
    while (1) {
        cin >> s;
        if (s == "0") break;
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1')
                sum += 2;
            else if (s[i] == '0')
                sum += 4;
            else
                sum += 3;
        }
        sum += s.length() + 1;
        cout << sum << "\n";
    }
    return 0;
}
