#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (1) {
        int sum = 1;
        vector<int> v;
        v.push_back(1);
        cin >> n;
        if (n == -1) return 0;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0) {
                v.push_back(i);
                v.push_back(n / i);
                sum += i + n / i;
            }
        if (sum == n) {
            sort(v.begin(), v.end());
            cout << n << " = " << v[0];
            for (int i = 1; i < v.size(); i++) cout << " + " << v[i];
            cout << "\n";
        } else {
            cout << n << " is NOT perfect.\n";
        }
    }
    return 0;
}
