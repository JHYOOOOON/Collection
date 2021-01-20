#include <cmath>
#include <iostream>
#define MAX 1000 + 1
using namespace std;

int n;
bool d[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = d[3] = 0;
    d[2] = d[4] = 1;

    for (int i = 5; i <= n; i++)
        d[i] = (d[i - 1] && d[i - 3] && d[i - 4]) ? 0 : 1;

    (d[n]) ? cout << "SK\n" : cout << "CY\n";
    return 0;
}
