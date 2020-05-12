#include <iostream>
#include <list>
using namespace std;

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        list<char> l;
        cin >> s;
        auto cur = l.end();
        for(int i=0; i<s.length(); i++){
            if(s[i] == '<' && cur != l.begin()){
                cur--;
            } else if(s[i] == '>' && cur != l.end()){
                cur++;
            } else if(s[i] == '-' && cur != l.begin()){
                cur--;
                cur = l.erase(cur);
            } else if(s[i] != '<' && s[i] != '>' && s[i] != '-'){
                l.insert(cur, s[i]);
            }
        }
        for(char i: l) cout << i;
        cout << "\n";
    }

    return 0;
}
