#include <algorithm>
#include <iostream>
using namespace std;

string d[10001];
string sum(string a, string b) {
    string ans = "";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while (a.length() < b.length()) a += '0';
    while (b.length() < a.length()) b += '0';

    int n, carry = 0;
    for (int i = 0; i < a.length(); i++) {
        n = (a[i] - '0' + b[i] - '0' + carry) % 10;
        ans += to_string(n);
        carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
    }
    if (carry) ans += to_string(carry);

    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    int n;
    cin >> n;

    d[0] = '0';
    d[1] = d[2] = '1';

    for (int i = 3; i <= n; i++) d[i] = sum(d[i - 1], d[i - 2]);

    cout << d[n] << "\n";

    return 0;
}
