#include <iostream>
#include <list>
using namespace std;

int main(){
    list<char> l;
    char tmp, x;
    int t;
    string s;
    cin >> s >> t;
    for(char tmp : s) l.push_back(tmp);
    auto idx = l.end();
    
    while(t--){
        cin >> tmp;
        if(tmp == 'L'){
            if(idx != l.begin()) idx--;
        } else if(tmp == 'D'){
            if(idx != l.end()) idx++;
        } else if(tmp == 'B'){
            if(idx != l.begin()){
                idx--;
                idx = l.erase(idx);
            }
        } else{
            cin >> x;
            l.insert(idx, x);
        }
    }

    for(char tmp: l) cout << tmp;
    

    return 0;
}
