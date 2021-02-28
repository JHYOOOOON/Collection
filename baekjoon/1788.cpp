#include <iostream>
#define MAX 1000000 + 1
#define MOD 1000000000
using namespace std;

long long n;
long long d[MAX] = {0, 1};

bool flag;

int main() {
    cin >> n;

    if (n == 0) {
        cout << "0\n0\n";
        return 0;
    }

    if (n > 0)
        flag = true;
    else {
        flag = false;
        n *= -1;
    }

    for (int i = 2; i <= n; i++) d[i] = (d[i - 1] + d[i - 2]) % MOD;

    if (flag) {
        cout << "1\n";
    } else {
        (n % 2) ? cout << "1\n" : cout << "-1\n";
    }
    cout << d[n] << "\n";

    return 0;
}
