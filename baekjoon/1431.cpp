#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int sum_str(string x) {
    int sm = 0;
    for (int i = 0; i < x.length(); i++)
        if (x[i] >= '0' && x[i] <= '9') sm += x[i] - '0';
    return sm;
}

bool compare(string a, string b) {
    if (a.length() != b.length()) return a.length() < b.length();

    int sum_a = 0, sum_b = 0, len = a.length();
    sum_a = sum_str(a);
    sum_b = sum_str(b);

    if (sum_a != sum_b)
        return sum_a < sum_b;
    else
        return a < b;
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++) cout << v[i] << "\n";

    return 0;
}
