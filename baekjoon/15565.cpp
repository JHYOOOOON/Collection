#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> doll(n);
    for (int i = 0; i < n; i++) cin >> doll[i];

    int len = MAX;
    int right = 0;
    int left = 0;
    int lion = 0;

    while (left <= right && right <= n) {
        if (lion >= k) {
            len = min(len, right - left);
            if (doll[left++] == 1) lion--;
        } else {
            if (doll[right++] == 1) lion++;
        }
    }

    (len == MAX) ? cout << -1 : cout << len;
    return 0;
}
