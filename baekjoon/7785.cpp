#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, string, greater<string>> company;
    int n;
    cin >> n;
    string a, b;

    for(int i=0; i<n; i++){
        cin >> a >> b;
        if(b == "leave")
            company.erase(a);
        else
            company.insert({a, b});
    }
    for(auto iter = company.begin(); iter != company.end(); iter++)
        cout << iter->first << "\n";
    return 0;
}
