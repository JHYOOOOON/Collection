#include <iostream>
#include <vector>
#define MAX 2000000000
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> liquid(n);
    for (int i = 0; i < n; i++) cin >> liquid[i];

    int left = 0, right = n - 1;
    int a, b;
    int mixed = MAX;

    while (left < right) {
        int tmpMixed = liquid[left] + liquid[right];
        if (abs(tmpMixed) < mixed) {
            mixed = abs(tmpMixed);
            a = liquid[left];
            b = liquid[right];
        }
        if (tmpMixed < 0)
            left++;
        else
            right--;
    }

    cout << a << ' ' << b << "\n";
    return 0;
}
