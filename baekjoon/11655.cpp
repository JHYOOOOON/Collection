#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    for(int i=0; i<s.length(); i++){
        if((s[i] >= 'A' && s[i] <= 'A'+12) || (s[i] >= 'a' && s[i] <= 'a'+12)){
            s[i] += 13;
        } else if((s[i] >= 'A'+13 && s[i] <= 'Z') || (s[i] >= 'A'+13 && s[i] <='z')){
            s[i] -= 13;
        }
    }
    for(int i=0; i<s.length(); i++){
        cout << s[i];
    }
    return 0;
}
