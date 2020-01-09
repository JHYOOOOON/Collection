#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<string> v(s.size());
    for(int i=0; i<s.size(); i++){
        v[i] = s.substr(i);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<s.size(); i++){
        cout << v[i] << "\n";
    }
    return 0;
}
