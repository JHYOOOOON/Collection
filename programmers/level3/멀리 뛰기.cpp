#include <string>
#include <vector>
#define MOD 1234567

using namespace std;

long long solution(int n) {
    vector<long long> d(n+1, 0);
    d[1] = 1;
    d[2] = 2;
    for(int i=3; i<=n; i++) d[i] = (d[i-2] + d[i-1]) % MOD;
    return d[n];
}
