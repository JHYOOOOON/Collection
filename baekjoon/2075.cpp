#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;
    for (int i = 0; i < n * n; i++) {
        cin >> tmp;
        if (pq.size() < n)
            pq.push(tmp);
        else if (pq.size() == n) {
            if (pq.top() < tmp) {
                pq.pop();
                pq.push(tmp);
            }
        }
    }

    cout << pq.top() << "\n";
    return 0;
}
