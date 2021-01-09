#include <iostream>
#define MAX 10000 + 1
using namespace std;

int d[MAX][4] = {0};

int main() {
    int t;
    cin >> t;

    d[1][1] = d[2][1] = d[2][2] = d[3][1] = d[3][2] = d[3][3] = 1;
    for (int i = 4; i < MAX; i++) {
        d[i][1] = d[i - 1][1];
        d[i][2] = d[i - 2][1] + d[i - 2][2];
        d[i][3] = d[i - 3][1] + d[i - 3][2] + d[i - 3][3];
    }

    int n;
    while (t--) {
        cin >> n;
        cout << d[n][1] + d[n][2] + d[n][3] << "\n";
    }

    return 0;
}
