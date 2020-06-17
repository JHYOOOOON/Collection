#include <iostream>
using namespace std;

int main() {
    string s;
    int age, weight;

    while (1) {
        cin >> s >> age >> weight;
        if (s == "#" && !age && !weight) return 0;

        if (age > 17 || weight >= 80)
            cout << s << " Senior\n";
        else
            cout << s << " Junior\n";
    }

    return 0;
}
