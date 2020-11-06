#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int x, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    cin >> n;
    while (n--) {
        cin >> x;
        if (x == 0) {
            if (!pq.empty()) {
                cout << pq.top().second << "\n";
                pq.pop();
            } else
                cout << "0\n";

        } else if (x < 0) {
            pq.push({x * -1, x});
        } else {
            pq.push({x, x});
        }
    }

    return 0;
}
