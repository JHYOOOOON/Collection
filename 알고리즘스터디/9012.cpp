#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string s;
    cin >> t;
    
    while(t--){
        cin >> s;
        stack<char> st;
        bool flag = true;

        for(char c:s){
            if(c == '('){ st.push(c); }
            else{
                if(st.empty() || st.top() == ')'){
                    flag = false;
                    break;
                } else{ st.pop(); }
            }
        }

        (st.empty() && flag) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
