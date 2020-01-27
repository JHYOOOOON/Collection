#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    vector<int> v;
    string tmp;
    int num = 0;
    cin >> s;

    for(int i=0; i<=s.length(); i++){
        if(s[i] == '-' || s[i] == '\0'){
            v.push_back(num + stoi(tmp));
            tmp = ""; num = 0;
        } else if(s[i] == '+'){
                num += stoi(tmp);
                tmp = "";
        }
        else { tmp += s[i]; }

    }
    for(int i=1; i<v.size(); i++)
        v[0] -= v[i];

    cout << v[0] << "\n";

    return 0;
}
