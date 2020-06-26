#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    string s;
    while (t--) {
        cin >> s;
        int len = sqrt(s.length());
        vector<vector<char>> v(len + 1, vector<char>(len + 1));
        int idx = 0;
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++) v[i][j] = s[idx++];

        for (int i = len - 1; i >= 0; i--)
            for (int j = 0; j < len; j++) cout << v[j][i];

        cout << "\n";
    }
    return 0;
}
