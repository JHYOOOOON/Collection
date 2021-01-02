#include <iostream>
#define MAX 1000000 + 5
using namespace std;

char answer[MAX];
string str, bomb;

int main() {
    cin >> str >> bomb;

    int idx = 0;
    for (char c : str) {
        answer[idx++] = c;
        int i = bomb.length() - 1;
        if (c == bomb[i]) {
            bool flag = false;
            int n = idx - bomb.length();
            for (int j = idx - 1; j >= n; j--) {
                if (answer[j] == bomb[i--]) {
                    flag = true;
                } else {
                    flag = false;
                    break;
                }
            }

            if (flag) idx -= bomb.length();
        }
    }

    if (idx == 0)
        cout << "FRULA\n";
    else {
        for (int i = 0; i < idx; i++) cout << answer[i];
        cout << "\n";
    }
    return 0;
}
