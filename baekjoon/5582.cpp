#include <iostream>
#define MAX 4000 + 1
using namespace std;

string a, b;
int d[MAX][MAX];

int main() {
    cin >> a >> b;

    int mx = 0;
    for (int i = 1; i <= a.length(); i++)
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
            mx = max(mx, d[i][j]);
        }

    cout << mx << "\n";

    return 0;
}
