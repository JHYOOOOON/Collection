#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ans;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    stack<int> s;
    for (int j = n - 1; j >= 0; j--) {
        while (!s.empty() && s.top() <= v[j]) s.pop();
        (s.empty()) ? ans.push_back(-1) : ans.push_back(s.top());
        s.push(v[j]);
    }

    for (int i = n - 1; i >= 0; i--) cout << ans[i] << ' ';

    return 0;
}
