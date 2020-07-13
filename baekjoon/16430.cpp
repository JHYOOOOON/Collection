#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int c = 0;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    a = b - a;
    int c = gcd(a, b);
    cout << a / c << ' ' << b / c << "\n";
    return 0;
}
