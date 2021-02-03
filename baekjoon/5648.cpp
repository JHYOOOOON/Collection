#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<string> num;

bool compare(string a, string b) {
    if (a.length() != b.length()) return a.length() < b.length();
    return a < b;
}

int main() {
    cin >> n;

    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        reverse(tmp.begin(), tmp.end());

        int idx = 0;
        for (int i = 0; i < tmp.length(); i++)
            if (tmp[i] != '0') {
                idx = i;
                break;
            }

        tmp = tmp.substr(idx);
        num.push_back(tmp);
    }

    sort(num.begin(), num.end(), compare);
    for (string s : num) cout << s << "\n";

    return 0;
}
