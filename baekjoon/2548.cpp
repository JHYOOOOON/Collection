#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int arr[20001];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);
    (n % 2) ? cout << arr[n / 2] << "\n" : cout << arr[n / 2 - 1] << "\n";
    return 0;
}
