#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[3];
    while(1){
        cin >> a[0] >> a[1] >> a[2];
        if(!a[0] && !a[1] && !a[2]) break;
        sort(a, a+3);
        (a[0]*a[0] + a[1]*a[1] == a[2]*a[2]) ? cout << "right" << "\n" : cout << "wrong" << "\n";
    }
    return 0;
}
