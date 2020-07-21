#include <algorithm>
#include <iostream>
using namespace std;
int l, c;
char alpha[20];

void make_str(int pos, string str, int ja, int mo) {
    if (str.size() == l) {
        if (ja < 2 || mo < 1) return;
        cout << str << "\n";
    }

    for (int i = pos; i < c; i++) {
        if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' ||
            alpha[i] == 'o' || alpha[i] == 'u')
            make_str(i + 1, str + alpha[i], ja, mo + 1);
        else
            make_str(i + 1, str + alpha[i], ja + 1, mo);
    }
}

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) cin >> alpha[i];

    sort(alpha, alpha + c);

    make_str(0, "", 0, 0);

    return 0;
}
