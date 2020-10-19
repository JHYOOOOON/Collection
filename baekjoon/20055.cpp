#include <iostream>
#include <vector>
using namespace std;

int n, k;
bool robot[101];
int d[201];
bool flag = true;
int stage = 1;

void confirm() {
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++)
        if (!d[i]) cnt++;
    if (cnt >= k) flag = false;
    return;
}

void moveRobot() {
    for (int i = n - 1; i >= 0; i--) {
        if (robot[i]) {
            if (i == n - 1)
                robot[i] = 0;
            else {
                if (robot[i + 1] || d[i + 1] < 1) continue;
                robot[i + 1] = 1;
                robot[i] = 0;
                d[i + 1]--;
            }
        }
    }
    if (!robot[0] && d[0]) {
        robot[0] = 1;
        d[0]--;
    }
    return;
}

void rotate() {
    vector<int> tmp(2 * n);
    for (int i = 0; i < 2 * n; i++)
        (i == 2 * n - 1) ? tmp[0] = d[2 * n - 1] : tmp[i + 1] = d[i];

    for (int i = 0; i < 2 * n; i++) d[i] = tmp[i];

    for (int i = n - 1; i >= 0; i--) {
        if (robot[i]) {
            if (i == n - 1)
                robot[i] = 0;
            else {
                robot[i + 1] = 1;
                robot[i] = 0;
            }
        }
    }
    return;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++) cin >> d[i];
    while (1) {
        rotate();
        moveRobot();

        confirm();
        if (flag)
            stage++;
        else
            break;
    }

    cout << stage << "\n";
    return 0;
}
