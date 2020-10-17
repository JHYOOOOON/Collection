#include <iostream>
#define MAX 1000000 + 1
using namespace std;

int n, m;
int a[MAX], b[MAX], c[MAX + MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0, idx = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j])
            c[idx++] = a[i++];
        else
            c[idx++] = b[j++];
    }
    while (i < n) c[idx++] = a[i++];
    while (j < m) c[idx++] = b[j++];

    for (int i = 0; i < n + m; i++) cout << c[i] << ' ';
    return 0;
}
