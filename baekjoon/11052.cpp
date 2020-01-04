#include <bits/stdc++.h>
using namespace std;

int n, mx = 0;
int c[10005], d[10005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[0] = c[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> c[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            d[i] = max(d[i], d[i-j] + c[j]);
        }
    }
    cout << d[n] << endl;
    return 0;
}
