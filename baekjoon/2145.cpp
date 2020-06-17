#include <iostream>
using namespace std;

int nanum(int x) {
    int sum = 0;
    while (x >= 1) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int n;
    while (1) {
        cin >> n;
        if (!n) return 0;
        while (n >= 10) n = nanum(n);
        cout << n << "\n";
    }
    return 0;
}
