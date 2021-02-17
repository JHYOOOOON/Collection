#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    (n % 2) ? cout << "SK\n" : cout << "CY\n";

    return 0;
}
