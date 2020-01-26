#include <bits/stdc++.h>
using namespace std;

int main(){
    int e, s, m;
    int year = 1;
    int a = 1, b = 1, c = 1;
    cin >> e >> s >> m;

    while(1){
        if(a == e && b == s && c == m) break;
        (a == 15) ? a = 1 : a++;
        (b == 28) ? b = 1 : b++;
        (c == 19) ? c = 1 : c++;
        year++;
    }

    cout << year << "\n";

    return 0;
}
