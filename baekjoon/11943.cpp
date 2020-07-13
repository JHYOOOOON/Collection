#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    (a + d < b + c) ? cout << a + d << "\n" : cout << b + c << "\n";

    return 0;
}
