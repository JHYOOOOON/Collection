#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n, tmp, stack[100001], index = -1;
    cin >> n;

    while(n--){
        cin >> s;
        if(s == "push"){
            cin >> tmp;
            stack[++index] = tmp;
        } else if(s == "top"){
            if(index == -1) { cout << -1 << endl; }
            else { cout << stack[index] << endl; }
        } else if(s == "pop"){
            if(index == -1){ cout << -1 << endl; }
            else{
                cout << stack[index] << endl;
                stack[index--] = 0;
            }
        } else if(s == "empty"){
            if(index == -1){ cout << 1 << endl; }
            else{ cout << 0 << endl; }
        } else if(s == "size"){ cout << index + 1 << endl;}
    }
    return 0;
}
