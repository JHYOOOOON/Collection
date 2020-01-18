#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a(21);
    int c, d;
    for(int i=1; i<21; i++) a[i] = i;
    for(int i=0; i<10; i++){
        cin >> c >> d;
        reverse(a.begin()+c, a.begin()+d+1);
    }
    for(int i=1; i<21; i++){
        cout << a[i] << ' ';
    }
    return 0;
}
