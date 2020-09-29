#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, nw, p, tmp;
    vector<int> score;

    cin >> n >> nw >> p;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        score.push_back(tmp);
    }

    if (n >= p && score[p - 1] >= nw) {
        cout << -1 << "\n";
    } else {
        int rank = 1;
        for (int i = 0; i < n; i++)
            if (score[i] > nw) rank++;
        cout << rank << "\n";
    }

    return 0;
}
