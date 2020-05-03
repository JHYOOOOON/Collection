#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, tmp, y=0, m=0;
    cin >> n;
    while(n--){
        cin >> tmp;
        y += (tmp/30 + 1) * 10;
        m += (tmp/60 + 1) * 15;
    }

    if(y == m) { cout << "Y M " << y << "\n"; }
    else { (y < m) ? cout << "Y " << y << "\n" : cout << "M " << m << "\n"; }
}
