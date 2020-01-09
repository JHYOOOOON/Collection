#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    a = a+b;
    c = c+d;
    cout << stoll(a)+stoll(c) << "\n";
    return 0;
}
