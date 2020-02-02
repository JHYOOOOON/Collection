#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, d[21];
    cin >> n;
    d[0] = 0;
    d[1] = 1;
    for(int i=2; i<=n; i++)
        d[i] = d[i-1]+d[i-2];
    cout << d[n] << "\n";
    return 0;
}
