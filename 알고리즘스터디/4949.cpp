#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;

    while(1){
        stack<int> s;
        bool flag = true;
        getline(cin, str);
        if(str == ".") return 0;
        for(char c:str){
            if(c == '(' || c == '[')
                s.push(c);
            else if(c == ')'){
                if(s.empty() || s.top() == '['){
                    flag = false;
                    break;
                } else{ s.pop(); }
            } else if(c == ']'){
                if(s.empty() || s.top() == '('){
                    flag = false;
                    break;
                } else{ s.pop(); }
            }
        }
        (!s.empty() || !flag) ? cout << "no\n" : cout << "yes\n";
    }

    return 0;
}
