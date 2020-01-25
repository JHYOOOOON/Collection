#include <bits/stdc++.h>
using namespace std;

long long multi(long long a, long long b, long long c){
    if(b == 1) return a;
    long long tmp = multi(a, b/2, c);
    if(b%2) return ((tmp*tmp) % c * a) % c;
    else return (tmp*tmp) % c;
}

int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    cout << multi(a%c, b, c) << "\n";
    return 0;
}
