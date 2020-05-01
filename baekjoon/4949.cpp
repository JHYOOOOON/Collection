#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        string str;
        bool flag = true;
        getline(cin, str);

        if(str == ".") return 0;

        stack<char> s;
        for(int i=0; i<str.length(); i++){
            if(str[i] == '(' || str[i] == '[')
                s.push(str[i]);
            else if(str[i] == ')' || str[i] == ']'){
                if(s.empty() || (str[i] == ')' && s.top()== '[') || (str[i] == ']' && s.top() == '(')){
                    flag = false;
                    break;
                }
                if(str[i] == ')' && s.top() == '(')
                    s.pop();
                else if(str[i] == ']' && s.top() == '[')
                    s.pop();
            }
        }

        if(s.empty() && flag) { cout << "yes" << "\n"; }
        else { cout << "no" << "\n"; }
    }
}
​
[출처] 백준 4949번: 균형잡힌 세상|작성자 와
