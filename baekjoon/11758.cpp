#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int s = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

    if (s == 0)
        cout << "0\n";
    else if (s > 0)
        cout << "1\n";
    else
        cout << "-1\n";

    return 0;
}
