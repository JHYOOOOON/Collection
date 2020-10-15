#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[10001];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && arr[i] < 1 && arr[i + 1] < 1) {
            sum += arr[i] * arr[i + 1];
            i++;
        } else if (arr[i] > 1)
            break;
        else
            sum += arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i - 1 >= 0 && arr[i] > 1 && arr[i - 1] > 1) {
            sum += arr[i] * arr[i - 1];
            i--;
        } else if (arr[i] <= 1)
            break;
        else
            sum += arr[i];
    }

    cout << sum << "\n";
}
