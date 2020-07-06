#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a, b;
    vector<int> a_arr, b_arr;
    cin >> a >> b;
    for (char n : a) a_arr.push_back(n - '0');
    for (char n : b) b_arr.push_back(n - '0');

    long long sum = 0;
    for (int i = 0; i < a_arr.size(); i++)
        for (int j = 0; j < b_arr.size(); j++) sum += a_arr[i] * b_arr[j];

    cout << sum << "\n";

    return 0;
}
