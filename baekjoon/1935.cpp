#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, alpha[26];
    string str;
    cin >> n >> str;
    for (int i = 0; i < n; i++) cin >> alpha[i];

    stack<double> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            s.push(alpha[str[i] - 'A']);
        else {
            double y = s.top();
            s.pop();
            double x = s.top();
            s.pop();
            switch (str[i]) {
                case '+': {
                    s.push(x + y);
                    break;
                }
                case '-': {
                    s.push(x - y);
                    break;
                }
                case '*': {
                    s.push(x * y);
                    break;
                }
                case '/': {
                    s.push(x / y);
                    break;
                }
            }
        }
    }
    printf("%.2f\n", s.top());
    return 0;
}
