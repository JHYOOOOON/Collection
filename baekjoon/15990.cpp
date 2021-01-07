#include <iostream>
#define MOD 1000000009
#define MAX 100000 + 1
using namespace std;

int t, n;
long long d[MAX][4] {0};

int main(){
    cin >> t;

    d[1][1] = d[2][2] = d[3][3] = d[3][1] = d[3][2] = 1;
    for(int i=4; i<MAX; i++){
        d[i][1] = (d[i-1][2] + d[i-1][3]) % MOD;
        d[i][2] = (d[i-2][1] + d[i-2][3]) % MOD;
        d[i][3] = (d[i-3][1] + d[i-3][2]) % MOD;
    }

    while(t--){
        cin >> n;
        cout << (d[n][1] + d[n][2] + d[n][3]) % MOD << "\n";
    }
    
    return 0;
}
