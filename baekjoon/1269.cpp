#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m, tmp;
    set<int> s;
    cin >> n >> m;

    while (n--) {
        cin >> tmp;
        s.insert(tmp);
    }

    while (m--) {
        cin >> tmp;
        if (s.find(tmp) == s.end())
            s.insert(tmp);
        else
            s.erase(tmp);
    }

    cout << s.size() << "\n";

    return 0;
}
