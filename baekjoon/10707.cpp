#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, p;
    cin >> a >> b >> c >> d >> p;

    int x = 0, y = 0;
    x = a * p;
    y = (p <= c) ? b : b + (p - c) * d;

    (x < y) ? cout << x << "\n" : cout << y << "\n";

    return 0;
}
