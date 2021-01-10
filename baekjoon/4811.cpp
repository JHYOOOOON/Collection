#include <iostream>
#define MAX 30 + 1
using namespace std;

long long d[MAX][MAX];

long long medicine(int w, int h) {
    if (w < 0 || h < 0) return 0;
    if (w == 0) return 1;

    long long tmp = d[w][h];
    if (tmp != 0) return tmp;
    return d[w][h] = medicine(w, h - 1) + medicine(w - 1, h + 1);
}

int main() {
    medicine(30, 0);

    int n;
    while (1) {
        cin >> n;
        if (n == 0) break;
        cout << d[n][0] << "\n";
    }

    return 0;
}
