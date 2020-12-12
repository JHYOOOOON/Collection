#include <iostream>
#include <string>
#define MAX 20 + 1
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    bool check[MAX] = {0};

    string s;
    int x;
    cin >> n;

    while (n--) {
        cin >> s;
        if (s == "add") {
            cin >> x;
            check[x] = 1;
        } else if (s == "remove") {
            cin >> x;
            check[x] = 0;
        } else if (s == "check") {
            cin >> x;
            cout << check[x] << "\n";
        } else if (s == "toggle") {
            cin >> x;
            check[x] = check[x] ? 0 : 1;
        } else if (s == "all") {
            for (int i = 1; i < MAX; i++) check[i] = 1;
        } else if (s == "empty") {
            for (int i = 1; i < MAX; i++) check[i] = 0;
        }
    }

    return 0;
}
