#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    string str;
    int n, tmp;
    cin >> n;

    while(n--){
        cin >> str;
        if(str == "push"){
            cin >> tmp;
            s.push(tmp);
        } else if(str == "pop"){
            if(!s.empty()){
                cout << s.top() << "\n";
                s.pop();
            } else { cout << -1 << "\n"; }
        } else if(str == "size"){
            cout << s.size() << "\n";
        } else if(str == "empty"){
            (s.empty()) ? cout << 1 << "\n" : cout << 0 << "\n";
        } else if(str == "top"){
            (s.empty()) ? cout << -1 << "\n" : cout << s.top() << "\n";
        }
    }

    return 0;
}
