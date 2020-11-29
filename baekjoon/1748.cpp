#include <cmath>
#include <iostream>
using namespace std;

int main() {
    string n;
    cin >> n;

    int len = n.length();

    if (len == 1) {
        cout << n << "\n";
        return 0;
    }

    long ans = 0;
    for (int i = 1; i < len; i++) ans += i * (9 * pow(10, i - 1));

    ans += len * (stoi(n) - pow(10, len - 1) + 1);
    cout << ans << "\n";
    return 0;
}
