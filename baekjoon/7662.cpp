#include <iostream>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;

    int n, x;
    char c;
    while (t--) {
        cin >> n;
        multiset<int> mul;

        while (n--) {
            cin >> c >> x;
            if (c == 'I')
                mul.insert(x);
            else {
                if (!mul.empty()) {
                    if (x == 1) {
                        auto it = mul.end();
                        it--;
                        mul.erase(it);
                    } else {
                        mul.erase(mul.begin());
                    }
                }
            }
        }

        if (mul.empty()) {
            cout << "EMPTY\n";
        } else {
            auto it = mul.end();
            it--;
            cout << *it << ' ' << *mul.begin() << "\n";
        }
    }
    return 0;
}
