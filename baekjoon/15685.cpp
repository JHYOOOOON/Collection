#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
bool dragon[105][105] = {false};

int main() {
    int n;
    cin >> n;

    int x, y, d, g;
    while (n--) {
        cin >> x >> y >> d >> g;
        vector<int> dir;

        dir.push_back(d);
        for (int i = 0; i < g; i++)
            for (int j = dir.size() - 1; j >= 0; j--)
                dir.push_back((dir[j] + 1) % 4);

        dragon[y][x] = 1;
        for (int k : dir) {
            x += dx[k];
            y += dy[k];
            dragon[y][x] = 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            if (dragon[i][j] && dragon[i + 1][j] && dragon[i + 1][j + 1] &&
                dragon[i][j + 1])
                cnt++;

    cout << cnt << "\n";
    return 0;
}
