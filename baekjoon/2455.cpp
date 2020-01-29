#include <bits/stdc++.h>
using namespace std;

int main(){
    int people = 0;
    int in, out, mx = 0;
    for(int i=0; i<4; i++){
        cin >> out >> in;
        people = people + in - out;
        if(mx < people) { mx = people; }
    }
    cout << mx << "\n";
    return 0;
}
