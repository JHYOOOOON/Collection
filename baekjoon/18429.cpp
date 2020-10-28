#include <iostream>
using namespace std;

int n, k;
int kit[9];
bool isused[9];

int cnt = 0;

void select(int count, int weight) {
    if (weight < 500) return;
    if (count == n) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!isused[i]) {
            isused[i] = 1;
            select(count + 1, weight - k + kit[i]);
            isused[i] = 0;
        }
    }

    return;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> kit[i];

    for (int i = 0; i < n; i++) {
        isused[i] = 1;
        select(1, 500 - k + kit[i]);
        isused[i] = 0;
    }

    cout << cnt << "\n";
    return 0;
}
