#include <iostream>
#define MAX 500 + 1
using namespace std;

int h, w;
int block[MAX];
int rain = 0;

int main() {
    cin >> h >> w;
    for (int i = 0; i < w; i++) cin >> block[i];

    int mx = block[0];
    int idx = 0;
    for (int i = 1; i < w; i++) {
        if (block[i] >= mx) {
            for (int j = idx + 1; j < i; j++) {
                rain += block[idx] - block[j];
                block[j] = block[idx];
            }
            mx = block[i];
            idx = i;
        }
    }

    mx = block[w - 1];
    idx = w - 1;
    for (int i = w - 2; i >= 0; i--) {
        if (block[i] >= mx) {
            for (int j = idx - 1; j > i; j--) {
                rain += block[idx] - block[j];
                block[j] = block[idx];
            }
            mx = block[i];
            idx = i;
        }
    }

    cout << rain << "\n";
    return 0;
}
