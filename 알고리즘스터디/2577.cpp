#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, cnt[10] = {0};
    long long multi;
    cin >> a >> b >> c;
    multi = a * b * c;
    
    string s = to_string(multi);
    for(int i=0; i<s.length(); i++)
        cnt[s[i]-'0']++;
    
    for(int i=0; i<10; i++)
        cout << cnt[i] << "\n";
}
