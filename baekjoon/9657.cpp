#include <iostream>
#define MAX 1000 + 1
using namespace std;

int n;
bool d[MAX];

int main() {
    cin >> n;
    d[1] = d[3] = d[4] = 1;
    d[2] = 0;

    for (int i = 5; i <= n; i++)
        (d[i - 1] && d[i - 3] && d[i - 4]) ? d[i] = 0 : d[i] = 1;

    (d[n]) ? cout << "SK\n" : cout << "CY\n";
    return 0;
}
