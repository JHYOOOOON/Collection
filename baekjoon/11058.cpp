#include <iostream>
#define MAX 100 + 1
using namespace std;

long long d[MAX];

int main() {
    int n;
    cin >> n;

    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1] + 1;
        for (int j = 3; j <= i; j++)
            if (d[i] < d[i - j] * (j - 1)) d[i] = d[i - j] * (j - 1);
    }

    cout << d[n] << "\n";

    return 0;
}
