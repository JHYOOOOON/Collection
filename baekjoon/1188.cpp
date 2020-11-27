#include <iostream>
using namespace std;

int n, m;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cout << m - gcd(n, m) << "\n";
    return 0;
}
