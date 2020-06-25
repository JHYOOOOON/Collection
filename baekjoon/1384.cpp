#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, cnt = 1;
    while (1) {
        cin >> n;
        if (!n) return 0;
        vector<string> v(n);
        char a;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            for (int j = 1; j < n; j++) {
                cin >> a;
                if (a == 'N') {
                    int tmp = (i - j < 0) ? n + i - j : i - j;
                    q.push({tmp, i});
                }
            }
        }
        cout << "Group " << cnt++ << "\n";
        if (q.empty())
            cout << "Nobody was nasty\n";
        else
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                cout << v[cur.first] << " was nasty about " << v[cur.second]
                     << "\n";
            }
        cout << "\n";
    }
    return 0;
}
