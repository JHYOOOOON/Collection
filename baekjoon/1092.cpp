#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> crane(n);
    for (int i = 0; i < n; i++) cin >> crane[i];
    cin >> m;
    vector<int> box(m);
    for (int i = 0; i < m; i++) cin >> box[i];

    sort(crane.begin(), crane.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());

    if (crane[0] < box[0]) {
        cout << "-1\n";
        return 0;
    }

    int time = 0;
    while (!box.empty()) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < box.size(); j++)
                if (crane[i] >= box[j]) {
                    box.erase(box.begin() + j);
                    break;
                }
        time++;
    }

    cout << time << "\n";
    return 0;
}
