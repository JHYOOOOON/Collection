#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    int cnt = 1;
    while (1) {
        cin >> s;
        if (s[0] == '-') return 0;
        stack<char> st;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (st.empty() && s[i] == '}') {
                st.push('{');
                ans++;
            } else if (s[i] == '}')
                st.pop();
            else
                st.push('{');
        }
        ans += st.size() / 2;
        cout << cnt++ << ". " << ans << "\n";
    }
    return 0;
}
