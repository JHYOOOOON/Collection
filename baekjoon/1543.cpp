#include <iostream>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    if (a.length() < b.length()) {
        cout << "0\n";
    } else {
        int sum = 0;
        for (int i = 0; i <= a.length() - b.length(); i++) {
            for (int j = 0; j < b.length(); j++) {
                if (a[i + j] != b[j]) break;
                if (a[i + j] == b[j] && j == b.length() - 1) {
                    i += b.size() - 1;
                    sum++;
                }
            }
        }
        cout << sum << "\n";
    }

    return 0;
}
