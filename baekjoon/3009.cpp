#include <bits/stdc++.h>
using namespace std;

int main(){
    int x[3], y[3];
    for(int i=0; i<3; i++)
        cin >> x[i] >> y[i];
    sort(x, x+3);
    sort(y, y+3);
    (x[0] == x[1]) ? cout << x[2] << ' ' : cout << x[0] << ' ';
    (y[0] == y[1]) ? cout << y[2] << '\n' : cout << y[0] << '\n';
    return 0;
}
