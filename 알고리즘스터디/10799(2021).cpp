#include <iostream>
#include <stack>
using namespace std;

int main(){
    int ans = 0;
    string str;
    stack<char> st;
    char tmp;
    cin >> str;

    for(char c : str){
        if(c == '(') {
            st.push('(');
            tmp = '(';
        } else{
            st.pop();
            ans += (tmp == '(') ? st.size() : 1;
            tmp = ')';
        }
    }

    cout << ans << "\n";

    return 0;
}
