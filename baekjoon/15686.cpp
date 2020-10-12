#include <cmath>
#include <iostream>
#include <vector>
#define MAX 123456789
using namespace std;

int n, m;
int street = MAX;
vector<pair<int, int>> chickens, houses;
bool isused[15];

void caculate() {
    int city = 0;
    for (auto house : houses) {
        int tmp = MAX;
        for (int i = 0; i < chickens.size(); i++) {
            if (isused[i]) {
                int ab = abs(chickens[i].first - house.first) +
                         abs(chickens[i].second - house.second);
                if (tmp > ab) tmp = ab;
            }
        }
        if (tmp != MAX) city += tmp;
    }
    if (street > city) street = city;
}

void select(int index, int cnt) {
    if (cnt == m) caculate();

    for (int i = index; i < chickens.size(); i++) {
        if (!isused[i]) {
            isused[i] = 1;
            select(i + 1, cnt + 1);
            isused[i] = 0;
        }
    }
}

int main() {
    int tmp;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (tmp == 1)
                houses.push_back({i, j});
            else if (tmp == 2)
                chickens.push_back({i, j});
        }
    }

    select(0, 0);

    cout << street << "\n";
    return 0;
}
