#include <iostream>
#define MOD 1000000
#define K 1500000
using namespace std;

long long n;
int fibo[K] = {0, 1};

int main() {
    cin >> n;

    for (int i = 2; i < K; i++) {
        fibo[i] = (fibo[i - 2] + fibo[i - 1]);
        fibo[i] %= MOD;
    }

    cout << fibo[n % K] << "\n";
    return 0;
}
