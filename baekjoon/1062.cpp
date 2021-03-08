#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int n, k, mx_count = 0;
set<char> s;
vector<string> v;
vector<char> alpha;
bool isused[26];
string str, tmp;

void findMax() {
    int sum = 0;
    for (string word : v) {
        bool flag = true;
        for (char c : word)
            if (!isused[c - 'a']) {
                flag = false;
                break;
            }
        if (flag) sum++;
    }

    mx_count = max(mx_count, sum);
    return;
}

void check(int idx, int cnt) {
    if (cnt == k) {
        findMax();
        return;
    }

    for (int i = idx; i < alpha.size(); i++)
        if (!isused[alpha[i] - 'a']) {
            isused[alpha[i] - 'a'] = 1;
            check(i + 1, cnt + 1);
            isused[alpha[i] - 'a'] = 0;
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    k -= 5;
    if (k < 0) {
        cout << mx_count << "\n";
        return 0;
    }
    
    isused['a' - 'a'] = isused['c' - 'a'] = isused['t' - 'a'] = isused['i' - 'a'] = isused['n' - 'a'] = 1;

    for (int i = 0; i < n; i++) {
        cin >> str;
        tmp = str.substr(4, str.length() - 8);
        for (auto c : tmp)
            if (!isused[c - 'a']) s.insert(c);
        v.push_back(tmp);
    }

    for (auto it = s.begin(); it != s.end(); it++) alpha.push_back(*it);

    if (alpha.size() <= k)
        for (auto c : alpha) isused[c - 'a'] = 1;

    (alpha.size() <= k) ? findMax() : check(0, 0);
    cout << mx_count << "\n";

    return 0;
}
