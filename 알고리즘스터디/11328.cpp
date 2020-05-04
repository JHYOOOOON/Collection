#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    string a, b;
    cin >> t;

    while(t--){
        cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        (a == b) ? cout << "Possible\n" : cout << "Impossible\n";
    }
    
    return 0;
}
