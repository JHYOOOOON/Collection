#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    string s;
    stack<char> st;
    char tmp;
    cin >> s;

    for(char c: s){
        if(c == '('){
            st.push('(');
            tmp = '(';
        } else{
            st.pop();
            if(tmp == '('){ ans += st.size(); }
            else { ans++; }
            tmp = ')';
        }
    }
    cout << ans << "\n";

    return 0;
}
