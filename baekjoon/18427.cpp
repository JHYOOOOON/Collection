#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, H;
    cin >> N >> M >> H;
    cin.ignore();

    vector<vector<int>> block(N);
    for (int i = 0; i < N; i++) {
        string str;
        getline(cin, str);

        int tmp = 0;
        for (char s : str) {
            if (s == ' ') {
                block[i].push_back(tmp);
                tmp = 0;
            } else { tmp = tmp * 10 + (s - '0'); }
        }
        block[i].push_back(tmp);
    }

    vector<int> d(H + 1, 0);
    d[0] = 1;
    for (int i = 0; i < N; i++) {
        vector<pair<int, int>> v;
        for (int j = 0; j <= H; j++)
            for (int k = 0; k < block[i].size(); k++)
                if (d[j] && j + block[i][k] <= H)
                    v.push_back({j + block[i][k], d[j]});

        for (pair<int, int> a : v) d[a.first] = (d[a.first] + a.second) % 10007;
    }

    cout << d[H] << "\n";
    return 0;
}
