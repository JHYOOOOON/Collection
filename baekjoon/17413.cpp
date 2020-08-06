#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    bool flag = false;
    getline(cin, s);

    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (!flag) {
            if ((s[i] == ' ' || s[i] == '<')) {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << s[i];
            } else
                st.push(s[i]);
        } else
            cout << s[i];
        if (s[i] == '<')
            flag = true;
        else if (s[i] == '>')
            flag = false;
    }

    if (!st.empty())
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }

    return 0;
}
