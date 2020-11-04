#include <iostream>
#define MAX 100 + 1
#define INF 10000
using namespace std;

int n;
int d[MAX][MAX];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) fill(d[i], d[i] + 1 + n, INF);

    bool tmp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (tmp) d[i][j] = 1;
        }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            (d[i][j] == INF) ? cout << "0 " : cout << "1 ";
        cout << "\n";
    }
    return 0;
}
