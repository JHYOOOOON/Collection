#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y, w, h, mn;
    cin >> x >> y >> w >> h;
    mn = min(x, min(y, min(abs(x-w), abs(y-h))));
    cout << mn << "\n";
    return 0;
}
