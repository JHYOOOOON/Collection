#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    string ans = "";
    while (n >= 1) {
        ans = (n % 2) ? '1' + ans : '0' + ans;
        n /= 2;
    }

    cout << ans << "\n";
    return 0;
}
