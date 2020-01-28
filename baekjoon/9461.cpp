#include <bits/stdc++.h>
using namespace std;

long long d[101];

int main(){
    int t, n;
    cin >> t;
    d[0] = 1;
    d[1] = 1;
    d[2] = 1;
    for(int i=3; i<101; i++)
        d[i] = d[i-2] + d[i-3];
    while(t--){
        cin >> n;
        cout << d[n-1] << "\n";
    }
    return 0;
}
