#include <iostream>
using namespace std;

int main() {
    int l, a, b, c, d, a_date, b_date;
    cin >> l >> a >> b >> c >> d;
    a_date = (a % c) ? a / c + 1 : a / c;
    b_date = (b % d) ? b / d + 1 : b / d;

    (a_date < b_date) ? cout << l - b_date << "\n" : cout << l - a_date << "\n";
    return 0;
}
