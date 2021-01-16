#include <iostream>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n;

    if (n == 0) {
        cout << "0\n";
        return 0;
    }

    while (n != 0) {
        if (n % -2) {
            s = '1' + s;
            n = (n - 1) / -2;
        } else {
            s = '0' + s;
            n /= -2;
        }
    }

    cout << s << "\n";
    return 0;
}
