#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    int c;
    while(b!=0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    int n, tmp;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    for(int i=1; i<n; i++){
        tmp = gcd(v[0], v[i]);
        cout << v[0] / tmp << '/' << v[i] / tmp << "\n";
    }

    return 0;
}
