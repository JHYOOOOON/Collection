#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    int c;
    while(b != 0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; i++)
            cin >> v[i];
        long long ans = 0;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                ans += gcd(v[i], v[j]);
        cout << ans << "\n";
    }
    return 0;
}
